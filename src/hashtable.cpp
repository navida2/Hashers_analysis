static ListNode * find(string key, ListNode * L);
static ListNode * insert(string key, ListNode * L);
static ListNode * remove(string key, ListNode * L);
static void print(ostream & out, ListNode * L);
static int length(ListNode * L);
static void delete_list(ListNode * L);
void error(string word, string msg);


void insert( const string & word);
bool find( const string & word);
void remove( const string & word);
bool is_empty();
bool is_full();
void print(ostream & out);
~HashTable();

size_t number_of_entries();
size_t number_of_chains();
void get_chain_lengths(vector<int> & v);
void insert_all_words(string file_name, HashTable & L);
void find_all_words(string file_name, HashTable & L);
void remove_all_words(string file_name, HashTable & L);

void measure_hashtable(string file_name, HashTable & L);
void measure_hashtables(string input_file);