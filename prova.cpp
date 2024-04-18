#include <iostream>
#include <vector>
#include <sstream>

struct coppia{
    std::string word;
    int fr{1};

    coppia(std::string s_in):word(s_in){}
};

//search function in vector
//if the string is present it will increment the fr by 1
//if the string is not present it will insert in the vector
bool search(std::vector<coppia>& v, std::string s){
    for(int i=0;i < v.size(); ++i){
        if(v[i].word == s){
            ++v[i].fr;
            return true;
        }
    }
    v.push_back(coppia(s));
    return false;
}

void print_fr(const std::vector<coppia>& v){
    std::cout << "Word Frequences!\n";
    for(int i=0;i<v.size();++i){
        std::cout << v[i].word << " : ";
        std::cout << v[i].fr << std::endl;
    }
}

int main(){

    //2. Print frequencies of individual words in a string

    std::string prova{"mi name es roberto roberto no cap es es"};
    std::string buffer;
    std::stringstream ss;
    std::vector<coppia> v;
    
    ss << prova;
    while(ss >> buffer){
        search(v,buffer);
    }

    print_fr(v);

    return 0;
}