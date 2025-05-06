ListNode * ListNode::find(string key, ListNode * L);
ListNode * ListNode::insert(string key, ListNode * L);
ListNode * ListNode::remove(string key, ListNode * L);
void ListNode::print(ostream & out, ListNode * L);
int ListNode::length(ListNode * L);
void ListNode::delete_list(ListNode * L);
void ListNode::error(string word, string msg);


void HashTable::insert( const string & word);
bool HashTable::find( const string & word);
void HashTable::remove( const string & word);
bool HashTable::is_empty();
bool HashTable::is_full();
void HashTable::print(ostream & out);
HashTable::~HashTable();

size_t HashTable::number_of_entries();
size_t HashTable::number_of_chains();
void HashTable::get_chain_lengths(vector<int> & v);

void insert_all_words(string file_name, HashTable & L);
void find_all_words(string file_name, HashTable & L);
void remove_all_words(string file_name, HashTable & L);

void measure_hashtable(string file_name, HashTable & L);
void measure_hashtables(string input_file);