#include "hashtable.h"
#include "Timer.h"
#include "stats.h"
#include <fstream>
#include <iostream>

ListNode * ListNode::find(string key, ListNode * L){
    if (L == nullptr){
        error("ListNode", " Is empty");
    }
    else{
        //loop through each checking if L.data == key then going to next if not
        ListNode* new_l = L;
        for(;new_l!=nullptr;){
            if(new_l->data == key){
                return new_l;
            }
            new_l = new_l->next;
        }
        return nullptr; 
    }
    return L;
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
    return L;
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
    
    for(;curr_node!=nullptr;){
        ListNode* next_node = curr_node->next;
        delete curr_node;
        curr_node=next_node;
//refacted this to assign lsit node at the front
    }
}
void error(string word, string msg){
    cout<<word<<msg<<endl;
}


void HashTable::insert( const string & word){
    size_t hash_value = hasher.hash(word,capacity);
    ListNode* list_at_hash_value = buf[hash_value];
    buf[hash_value] = ListNode::insert(word, list_at_hash_value);
}

bool HashTable::find( const string & word){
    //get the has value and then use find lsit node
    size_t hash_value = hasher.hash(word,capacity); //this is hashing value then u would get the buf index and pass into hash
    ListNode* list_at_hash_value = buf[hash_value];
    ListNode* found_or_not = ListNode::find(word, list_at_hash_value);
    return !(found_or_not==nullptr);

}

void HashTable::remove( const string & word){
    size_t hash_value = hasher.hash(word,capacity); 
    ListNode* list_at_hash_value = buf[hash_value];
    buf[hash_value] = ListNode::remove(word, list_at_hash_value);
}

bool HashTable::is_empty(){//use number of entries for this 
    return number_of_entries() == 0;
}
bool HashTable::is_full(){
    return false;
}
void HashTable::print(ostream & out){
    for(size_t i=0;i<capacity;++i){
        ListNode* to_print = buf[i];
        ListNode::print(out,to_print);
    }
}
HashTable::~HashTable(){
    for(size_t i =0;i<capacity;++i){
        ListNode* to_delete = buf[i];
        ListNode::delete_list(to_delete);
    }
    delete[] buf;
    
}

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
    
    for (size_t i=0; i<capacity;++i){
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
    v.resize(capacity);
    for (size_t i = 0; i<capacity;++i){
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

void insert_all_words(string file_name, HashTable & L){
    Timer t;
    double eTime;
    ifstream in(file_name);
    int limit = NWORDS /10;
    t.start();
    for (string word; (in>>word)&&limit>0; --limit){
        L.insert(word);
    }
    t.elapsedUserTime(eTime);
    in.close();
    cout<<"\t\tI = " <<eTime<<endl;
}
void find_all_words(string file_name, HashTable & L){
    Timer t;
    double eTime;
    ifstream in(file_name);
    int limit = NWORDS /10;
    t.start();
    for (string word; (in>>word)&&limit>0; --limit){
        L.find(word);
    }
    t.elapsedUserTime(eTime);
    in.close();
    cout<<"\t\tF = " <<eTime<<endl;
}
void remove_all_words(string file_name, HashTable & L){
    Timer t;
    double eTime;
    ifstream in(file_name);
    int limit = NWORDS /10;
    t.start();
    for (string word; (in>>word)&&limit>0; --limit){
        L.remove(word);
    }
    t.elapsedUserTime(eTime);
    in.close();
    cout<<"\t\tR = " <<eTime<<endl;
}

void measure_hashtable(string file_name, HashTable & L){
    cout<<L.get_name()<<endl;
    insert_all_words(file_name, L);

    vector<int> chain_lengths;
    L.get_chain_lengths(chain_lengths);
    Stats stats(L.get_name(), chain_lengths);
    stats.print(cout);

    find_all_words(file_name,L);
    remove_all_words(file_name, L);
    if(!L.is_empty()){
        error(L.get_name(), "is not empty");
    }

}

void measure_hashtables(string input_file){
    Hasher * H[] ={
        new ChatGPTHasher{},
        new GoodrichHasher{},
        new MultHasher{},
        new PreissHasher{},
        new PJWHasher{},
        
        new STLHasher{},
        new SumHasher{},
        new Weiss1Hasher{},
        new Weiss2Hasher{},
        new WeissHasher{},
        

    };
    int S[] = {
        10000,
        1000,
        100,
        10,
        1,
    };
    for (auto size:S){
        for(auto h:H){
            HashTable ht(*h,size);
            measure_hashtable(input_file,ht);
        }
    }
 
}