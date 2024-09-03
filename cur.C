#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char*)userp)[0] = '\0';

    return size * nmemb;
}

void send_request(char *prompt)
{
    CURL *curl;
    CURLcode res;
    char *api_key = "your_api_key_here";
    char *api_url = "https://api.openai.com/v1/engines/davinci-codex/completions";
    char *post_fields = "{\"prompt\": \"%s\", \"max_tokens\": 100, \"n\": 1, \"stop\": null, \"temperature\": 0.7}";
    char *response = malloc(CURL_MAX_WRITE_SIZE);

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl) 
    {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "Authorization: Bearer %s", api_key);

        curl_easy_setopt(curl, CURLOPT_URL, api_url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_fields);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(post_fields));
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    printf("%s\n", response);
    free(response);
}
int main()
{
    char *prompt = "What are the symptoms of COVID-19?";
    send_request(prompt);

    return 0;
}
