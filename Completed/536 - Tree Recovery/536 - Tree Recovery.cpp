#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sys/time.h>

#define NULL_CHAR '\0'
#define ARRAY_SIZE 30

using namespace std;


char preorder[ARRAY_SIZE],inorder[ARRAY_SIZE];
vector<char> postOrder;

void constructor ()
{
    postOrder.clear();
}

void process(string pre,string in){
    char ch = pre.at(0);
    int index = in.find(ch);
    if(index > 0){
        string newPre = pre.substr(1,index);
        string newIn = in.substr(0,index);
        process(newPre,newIn);
    }
    if(index < in.length() - 1){
        string newPre = pre.substr(index + 1);
        string newIn = in.substr(index + 1);
        process(newPre,newIn);
    }
    postOrder.push_back(ch);
}

int main(){
    string pre,in;

    while(scanf("%s %s",preorder,inorder)){
        struct timeval tp;
        gettimeofday(&tp, NULL);
        long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
        constructor();
        pre = preorder;
        in = inorder;
        process(pre,in);
        int len = postOrder.size();
        for(int i=0;i<len;i++){
            printf("%c",postOrder[i]);
        }
        printf("\n");
        gettimeofday(&tp, NULL);
        long int ms2 = tp.tv_sec * 1000 + tp.tv_usec / 1000;
        cout << "Time taken in this program: " << (ms2 - ms) << endl;
    }


    return 0;
}



