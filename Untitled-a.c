
#define BLOCK_DATA_SIZE 256

// Define a block structure
struct Block {
    int index;
    char timestamp[30];
    char previous_hash[65];
    char data[BLOCK_DATA_SIZE];
    char hash[65];
};

// Function to calculate the SHA-256 hash of a string
void calculate_hash(const char* input, char* output) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, input, strlen(input));
    SHA256_Final((unsigned char*)output, &ctx);
}

// Function to create a new block
struct Block create_block(int index, const char* previous_hash, const char* data) {
    struct Block block;
    block.index = index;
    time_t current_time = time(NULL);
    strftime(block.timestamp, sizeof(block.timestamp), "%Y-%m-%d %H:%M:%S", localtime(&current_time));
    strncpy(block.previous_hash, previous_hash, sizeof(block.previous_hash));
    strncpy(block.data, data, sizeof(block.data));

    // Calculate the hash of the block
    char block_data[BLOCK_DATA_SIZE + 128]; // +128 for other fields
    snprintf(block_data, sizeof(block_data), "%d%s%s%s", index, block.timestamp, previous_hash, data);
    calculate_hash(block_data, block.hash);

    return block;
}

int main() {
    // Create the genesis block
    struct Block genesis_block;
    genesis_block = create_block(0, "0", "Genesis Block");

    // Print the genesis block
    printf("Block #%d\n", genesis_block.index);
    printf("Timestamp: %s\n", genesis_block.timestamp);
    printf("Previous Hash: %s\n", genesis_block.previous_hash);
    printf("Data: %s\n", genesis_block.data);
    printf("Hash: %s\n", genesis_block.hash);

    return 0;
}
