#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Item {
  Item(int v, Item* n) { val = v; next = n; }
  int val;
  Item* next;
};

void readIntFile(char* filename, Item*& head1, Item*& head2);
void readLine(ifstream& ifile, Item*& head);


Item* concatenate(Item* head1, Item* head2);
void removeEvens(Item*& head);
Item* removeEvensHelper(Item* head);
double findAverage(Item* head);
double findAverageHelper(Item* head, int& size);

void readIntFile(char* filename, Item*& head1, Item*& head2)
{
  ifstream ifile(filename);
  if( ifile.fail()){
    cout << "Couldn't open " << filename << endl;
    head1 = NULL;
    head2 = NULL;
    return;
  }

  readLine(ifile, head1);
  readLine(ifile, head2);

  ifile.close();
  return;
}

void readLine(ifstream& ifile, Item*& head)
{
  head = NULL;
  Item* tail = head;
  int v;
  string line;
  getline(ifile, line);
  stringstream ss(line);
  while(ss >> v){
    Item* newptr = new Item(v, NULL);
    if(tail == NULL){
      tail = newptr;
      head = newptr;
    }
    else {
      tail->next = newptr;
      tail = newptr;
    }
  }
}

void removeEvens(Item*& head)
{
  head = removeEvensHelper(head);
}

Item* removeEvensHelper(Item* head)
{
  if(head == NULL){
    return NULL;
  }
  else {
    if(head->val % 2 != 0){
      head->next = removeEvensHelper(head->next);
      return head;
    }
    else {
      Item* nextEven = removeEvensHelper(head->next);
      delete head;
      return nextEven;
    }
  }
}

Item* concatenate(Item* head1, Item* head2)
{
  if (head1 == NULL && head2 == NULL){
    return NULL;
  }
  else if (head1 == NULL && head2 != NULL){
    return new Item(head2->val, concatenate(head1, head2->next));
  }
  else {
    return new Item(head1->val, concatenate(head1->next, head2));
  }
}

double findAverage(Item* head)
{
  int size = 0; 
  return findAverageHelper(head, size) / size;
}

double findAverageHelper(Item* head, int& size)
{
  if(head == NULL) return 0.0;
  else {
    size++;
    return head->val + findAverageHelper(head->next, size);
  }

}

void printList(std::ostream& ofile, Item* head)
{
  if(head == NULL)
    ofile << std::endl;
  else {
    ofile << head->val << " ";
    printList(ofile, head->next);    
  }
}
int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Usage: ./q4 input_file output_file" << endl;
    return 1;
  }
  Item* head1, *head2;
  readIntFile(argv[1], head1, head2);

  //  outputList(cout, head1);
  //  outputList(cout, head2);


  ofstream ofile(argv[2]);
  if(ofile.fail()){
    cerr << "Couldn't open output file " << argv[2] << endl;
  }
  
  Item* head3 = concatenate(head1, head2);
  printList(ofile, head3);
  removeEvens(head3);
  printList(ofile, head3);
  double avg =  findAverage(head3);
  printList(ofile, head3);
  //cout << avg << endl;
  //cout << avg << endl;
  //Item* headavg = new Item(avg,NULL);
  //printList(ofile,headavg);
  ofile<<avg;
  
  ofile.close();
  return 0;
}
