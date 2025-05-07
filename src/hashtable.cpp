ListNode * ListNode::find(string key, ListNode * L){
    if (L == nullptr){
        error("ListNode", " Is empty");
    }
    else{
        //loop through each checking if L.data == key then going to next if not
        ListNode* new_l = L
        for(;new_l!=nullptr;){
            if(new_l->data == key){
                return new_l;
            }
            new_l = new_l->next;
        }
        return nullptr; 
    }
}
ListNode * ListNode::insert(string key, ListNode * L){//insert at head
    ListNode* new_head = new ListNode(key,L);
    return new_head; 
}
ListNode * ListNode::remove(string key, ListNode * L){//remove the node that has the key
    if (L == nullptr){
        error("ListNode", " Is empty");
    }
    else{
        //first check if its head
        ListNode* main_node = L;
        ListNode* prev = L;
        if (main_node->data==key){
            ListNode* main_node = L;
            ListNode* prev_head = main_node;
            L = main_node->next;
            delete prev_head;
            return L;
        }
        //Now handke the ccase where its not the main node
        ListNode* nxt = L->next;
        for(;main_node!=nullptr;){
            if(main_node->data == key){
                ListNode* new_next =nxt;
                delete main_node;
                prev->next = new_next;
                return L;               
            }
            prev = main_node;
            main_node = main_node->next;
            nxt = main_node->next;
        }
    return L;
    }
}
void ListNode::print(ostream & out, ListNode * L){//Traverse list and print everything
    ListNode * printing_node = L;
    for(;printing_node!=nullptr;){
        out<<printing_node->data<<" ";
        printing_node = printing_node->next;
    }
}
int ListNode::length(ListNode * L){//count number of nodes in the list
    int len = 0;
    ListNode* curr_node = L;
    for(;curr_node!=nullptr;){
        ++len;
        curr_node=curr_node->next;
    }
    return len;

}
void ListNode::delete_list(ListNode * L){//trav the list deleting each node till its done
    ListNode* curr_node = L;
    ListNode* next_node = curr_node->next;
    for(;curr_node!=nullptr;){
        delete curr_node;
        curr_node=new_next;
        next_node = curr->next;

    }
}
void ListNode::error(string word, string msg){
    cout<<word<<msg<<endl;
}


void HashTable::insert( const string & word);

bool HashTable::find( const string & word);

void HashTable::remove( const string & word);

bool HashTable::is_empty(){//use number of entries for this 
    return number_of_entries() == 0;
}
bool HashTable::is_full(){
    return false;
}
void HashTable::print(ostream & out);
HashTable::~HashTable();

size_t HashTable::number_of_entries(){
    //loop through buf checking if each node is nullptr
    size_t num_entrys =0;
    
    for (size_t i=0; i<capacity;++i){
        ListNode* first_entry = buf[i];
        if (first_entry == nullptr){
            continue;
        }
        else{
            //add it so ther is sum countirng for chaininsssss
            for(;first_entry!=nullptr;first_entry = first_entry->next)
            num_entrys+=1;
        }
    //ask ta if there is sum way that this should call num of chains
    }
    return num_entrys;
}
size_t HashTable::number_of_chains(){
    //count how many non null there are
    size_t num_entrys =0;
    
    for (int i=0; i<capacity;++i){
        ListNode* first_entry = buf[i];
        if (first_entry == nullptr){
            continue;
        }
        else{
            num_entrys+=1;
        }
    
}
    return num_entrys;
}
void HashTable::get_chain_lengths(vector<int> & v){
    //loop thru the buff and then coun thechains and entreis

    for (int i = 0; i<capacity;++i){
        int num_per_buf = 0;
        ListNode* first_entry = buf[i];
        if(first_entry!=nullptr){
            for(;first_entry!=nullptr;first_entry=first_entry->next){
                num_per_buf+=1;
            }
        }

        v[i] = num_per_buf;
    }
}

void insert_all_words(string file_name, HashTable & L);
void find_all_words(string file_name, HashTable & L);
void remove_all_words(string file_name, HashTable & L);

void measure_hashtable(string file_name, HashTable & L);
void measure_hashtables(string input_file);