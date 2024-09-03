import time
import clarivate.wos_journals.client
from clarivate.wos_journals.client.api import journals_api
from clarivate.wos_journals.client.model.journal_list import JournalList
from pprint import pprint

# Set your API key
configuration = clarivate.wos_journals.client.Configuration()
configuration.api_key['key'] = 'YOUR_API_KEY'

# Create an instance of the API client
with clarivate.wos_journals.client.ApiClient(configuration) as api_client:
    # Create an instance of the API class
    api_instance = journals_api.JournalsApi(api_client)

    # Ask the user for the journal name
    journal_name = input("Enter the journal name: ")

    # Ask the user for the author name
    author_name = input("Enter the author name: ")

    # Ask the user for the year
    year = int(input("Enter the year: "))

    # Set the edition (e.g. SCIE, SSCI, AHCI, ESCI)
    edition = "SCIE"  # str | Filter by Web of Science Citation Index

    # Call the API to search for the journal
    api_response = api_instance.journals_get(q=journal_name, edition=edition, jcr_year=year)

    # Extract the impact ID from the response
    journal_list = api_response.body
    for journal in journal_list.journals:
        if journal.name == journal_name:
            impact_id = journal.metrics.impact_metrics.impact_id
            print(f"Impact ID for {journal_name}: {impact_id}")
            break
    else:
        print(f"Journal {journal_name} not found.")