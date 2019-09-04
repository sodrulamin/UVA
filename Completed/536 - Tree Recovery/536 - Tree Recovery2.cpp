#include<iostream>
#include<string>
using namespace std;
struct node
{
       char info;
       node *left;
       node *right;
};
long long pre;
node* construct_tree(string preorder, string inorder,int inStart, int inFinal)
{
     if(inStart>inFinal)
     {
         return NULL;
     }
     long long i,inIndex;
     node *temp=new node;
     temp->info=preorder[pre++];
     for(i=inStart;i<=inFinal;i++)
     {
          if(inorder[i]==temp->info)
          {
               inIndex=i;
          }
     }
     temp->left=construct_tree(preorder,inorder,inStart,inIndex-1);
     temp->right=construct_tree(preorder,inorder,inIndex+1,inFinal);
     return temp;
}

void postorder_traversal(node *r)
{
     if(r==NULL)
          return;
     postorder_traversal(r->left);

     postorder_traversal(r->right);
     cout<<r->info;
}
int main()
{

    string preorder,inorder,postorder;
    while(cin>>preorder>>inorder)
    {
          long long len_in=inorder.length();
          pre=0;
          node *root=construct_tree(preorder,inorder,0,len_in-1);
          postorder_traversal(root);
          cout<<endl;
    }

    return 0;
}
