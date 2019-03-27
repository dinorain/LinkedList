// djourdan555@gmail.com
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stack>

void hello(char *s) {
	printf("\n");
	printf("Hello %s!\n", s);
	printf("It's nice to meet you\n\n");
}

void exchange(int &value1, int &value2) {
    int temp; temp = value2; value2 = value1; value1 = temp;
}

struct tSingle {
    int anyData;
    tSingle *Prev, *Next;
} *Head=NULL, *Tail, *NewL, *DeleteL, *HelpL;


class singleList {
    public:
    	void initialize(int newData){
    		NewL = new tSingle;
    		NewL->anyData=newData;
    		NewL->Next=NULL;
			if(Head == NULL){
				Head = NewL;
				Tail = NewL;
			} else{
				Tail->Next = NewL;
				Tail = Tail->Next;
			}
		}
        void insertFront(int newData){
        	if(Head != NULL){
        		NewL = new tSingle;
				NewL->anyData=newData;
				NewL->Next = Head;
				Head = NewL;
			}
		}
        void insertEnd(int newData){
        	if(Head != NULL){
        		NewL = new tSingle;
				NewL->anyData=newData;
				NewL->Next=NULL;
				Tail->Next=NewL;
				Tail=NewL;
			}
		}
        void insertMiddle(int newData, int pos, int count){
        	if(pos > count){
				printf("Exceeded index!\n");
			}
        	if(Head != NULL){
        		NewL = new tSingle;
				NewL->anyData=newData;
				HelpL = Head;
				for(int i = 0; i < pos; i++){
					HelpL = HelpL->Next;
				}
				NewL->Next = HelpL->Next;
				HelpL->Next = NewL;
			}
		}
        void deleteFront(){
        	if(Head != NULL){
        		DeleteL=Head;
        		Head=Head->Next;
				delete DeleteL;
        	}
		}
        void deleteEnd(){
        	if(Head != NULL){
        		DeleteL=Tail;
        		Tail=Head;
        		while (Tail->Next != DeleteL){
        			Tail=Tail->Next;
				}
				Tail->Next=NULL;
				delete DeleteL;
        	}
		}
        void deleteMiddle(int pos, int count){
        	if(pos > count){
				printf("Exceeded index!\n");
			}
        	if(Head != NULL){
        		HelpL=Head;
        		for (int i=0; i<pos; i++){
        			HelpL=HelpL->Next;
				}
				DeleteL=HelpL->Next;
				HelpL->Next=DeleteL->Next;
				delete DeleteL;
        	}
		}
        void displayForward(){
        	HelpL=Head;
        	while (HelpL != NULL){
        		printf("%i ", HelpL->anyData);
        		HelpL=HelpL->Next;
			}
        }
        void displayBackward(){
        	HelpL=Tail;
        	while (HelpL != NULL){
        		printf("%i ", HelpL->anyData);
        		HelpL=HelpL->Prev;
			}
        }
		void sort(int size){
			tSingle *thisnode;
			thisnode = Head;
			for(int i = 0; i < size-1; i++){
				for(int j = 0; j < size-1; j++){
					if(thisnode->anyData > thisnode->Next->anyData){
						int temp = thisnode->anyData;
 						thisnode->anyData = thisnode->Next->anyData;
 						thisnode->Next->anyData = temp;
					}
					thisnode = thisnode->Next;
				}
				thisnode = Head;
			}
		}

		int count(){
			int c = 0;
			tSingle *curNode;
			curNode = Head;
			while(curNode != NULL){
				c++;
				curNode = curNode->Next;
			}
			return c;
		}
};

class doubleList {
    public:
    	void initialize(int newData){
    		NewL = new tSingle;
    		NewL->anyData=newData;
    		NewL->Prev=NULL;
    		NewL->Next=NULL;
			if(Head == NULL){
				Head = NewL;
				Tail = NewL;
			} else{
				Tail->Next = NewL;
				Tail = Tail->Next;
			}
		}
        void insertFront(int newData){
        	if(Head != NULL){
        		NewL = new tSingle;
				NewL->anyData=newData;
				NewL->Prev=NULL;
				NewL->Next = Head;
				Head->Prev=NewL;
				Head = NewL;
			}
		}
        void insertEnd(int newData){
        	if(Head != NULL){
        		NewL = new tSingle;
				NewL->anyData=newData;
				NewL->Prev=Tail;
				NewL->Next=NULL;
				Tail->Next=NewL;
				Tail=NewL;
			}
		}
        void insertMiddle(int newData, int pos, int count){
        	if(pos > count){
				printf("Exceeded index!\n");
			}
        	if(Head != NULL){
        		NewL = new tSingle;
				NewL->anyData=newData;
				HelpL = Head;
				for(int i = 0; i < pos; i++){
					HelpL = HelpL->Next;
				}
				NewL->Prev=HelpL;
				NewL->Next = HelpL->Next;
				HelpL->Next = NewL;
				HelpL=HelpL->Next;
				HelpL->Prev=NewL;
			}
		}
        void deleteFront(){
        	if(Head != NULL){
        		DeleteL=Head;
        		Head=Head->Next;
        		if (Head != NULL) {
                    Head->Prev=NULL;
				}
				delete DeleteL;
        	}
		}
        void deleteEnd(){
        	if(Head != NULL){
        		DeleteL=Tail;
        		Tail=Tail->Prev;
				if (Tail != NULL) {
                    Tail->Next=NULL;
				}
				delete DeleteL;
        	}
		}
        void deleteMiddle(int pos, int count){
        	if(pos > count){
				printf("Exceeded index!\n");
			}
        	if(Head != NULL){
        		HelpL=Head;
        		for (int i=0; i<pos; i++){
        			HelpL=HelpL->Next;
				}
				DeleteL=HelpL->Next;
				HelpL->Next=DeleteL->Next;
				HelpL=HelpL->Next;
				HelpL->Prev=DeleteL->Prev;
				delete DeleteL;
        	}
		}
        void displayForward(){
        	HelpL=Head;
        	while (HelpL != NULL){
        		printf("%i ", HelpL->anyData);
        		HelpL=HelpL->Next;
			}
        }
        void displayBackward(){
        	HelpL=Tail;
        	while (HelpL != NULL){
        		printf("%i ", HelpL->anyData);
        		HelpL=HelpL->Prev;
			}
        }
		void sort(int size){
			tSingle *thisnode;
			thisnode = Head;
			for(int i = 0; i < size-1; i++){
				for(int j = 0; j < size-1; j++){
					if(thisnode->anyData > thisnode->Next->anyData){
						int temp = thisnode->anyData;
 						thisnode->anyData = thisnode->Next->anyData;
 						thisnode->Next->anyData = temp;
					}
					thisnode = thisnode->Next;
				}
				thisnode = Head;
			}
		}

		int count(){
			int c = 0;
			tSingle *curNode;
			curNode = Head;
			while(curNode != NULL){
				c++;
				curNode = curNode->Next;
			}
			return c;
		}
};


int main () {
    char Name[30];
	printf("Hello... What is your name? ");
	scanf("%s", &Name);
	hello(Name);
	printf("\nLet's do your link operations...");
	printf("\n1. Single Linked List");
	printf("\n2. Double Linked List");
	int type;
	printf("\n Which one do you want ? (1 or 2) : "); scanf("%i", &type);

    int input_1, input_2, input_3, pos;
    char *pil = "Y";

    singleList list1;
    srand(std::time(0));
    int size;

	printf("\nHow many data do you want to start with ? "); scanf("%i", &size);
	printf("\nInitializing random data ...");

	for(int i = 0; i < size; i++){
		list1.initialize(rand() % 100);
	}

	if (type == 1) {
        while ((pil == "Y" || pil == "y" )&& input_1 != 9) {
            system("cls");
            list1.displayForward();
            printf("\n\nSingle Linked List\n");
            printf("========================\n");
            printf("1. Insert an element\n");
            printf("2. Delete an element\n");
            printf("3. Display\n");
            printf("4. Sort\n");
            printf("9. Exit\n");
            printf("What do you want to do with your list? "); scanf("%i", &input_1);
            printf("\n");
            if (input_1 == 1) { // Insert an element
                system("cls");
                list1.displayForward();
                printf("\nSingle Linked List >> Insert\n");
                printf("========================\n");
                printf("1. Insert Front\n");
                printf("2. Insert End\n");
                printf("3. Insert at certain postition\n");
                printf("9. Exit\n");
                printf("Where do you want to insert your element? "); scanf("%i", &input_2);
                printf("\n");
                if (input_2 == 1) { // input front
                    printf("Input your data : "); scanf("%i", &input_2);
                    list1.insertFront(input_2);
                    printf("\n\n Updated data : "); list1.displayForward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                } else if (input_2 == 2) { // input end
                    printf("Input your data : "); scanf("%i", &input_2);
                    list1.insertEnd(input_2);
                    printf("\n\n Updated data : "); list1.displayForward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                } else if (input_2 == 3) { // input at certain position
                    printf("Input your data: "); scanf("%i", &input_2);
                    printf("\nData's position: "); scanf("%i", &pos);
                    list1.insertMiddle(input_2, pos, list1.count());
                    printf("\n\n Updated data : "); list1.displayForward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                }
            } else if (input_1 == 2) { // Delete an element
                system("cls");
                list1.displayForward();
                printf("\nSingle Linked List >> Delete\n");
                printf("========================\n");
                printf("1. Delete Front\n");
                printf("2. Delete End\n");
                printf("3. Delete at certain postition\n");
                printf("9. Exit\n");
                printf("Which element do you want to delete?"); scanf("%i", &input_2);
                printf("\n");
                if (input_2 == 1) { // delete front
                    list1.deleteFront();
                    printf("\n\n Updated data : "); list1.displayForward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                } else if (input_2 == 2) { // delete end
                    list1.deleteEnd();
                    printf("\n\n Updated data : "); list1.displayForward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                } else if (input_2 == 3) { // delete at certain position
                    printf("\nThe postition of the element: "); scanf("%i", &pos);
                    list1.deleteMiddle(pos, list1.count());
                    printf("\n\n Updated data : "); list1.displayForward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                }
            } else if (input_1 = 3) { // display
                system("cls");
                list1.displayForward();
                printf("\nSingle Linked List >> Display\n");
                printf("========================\n");
                printf("1. Display Forward\n");
                printf("2. Display Backward\n");
                printf("9. Exit\n");
                printf("Which one do you like? "); scanf("%i", &input_2);
                printf("\n");
                if (input_2 == 1) { // display forward
                    list1.sort(list1.count());
                    printf("\n\n Updated data : "); list1.displayForward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                } else if (input_2 == 2) { // display backward
                    list1.sort(list1.count());
                    printf("\n\n Updated data : "); list1.displayBackward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                }
            } else if (input_1 == 4) { // sort
                list1.sort(list1.count());
                printf("\n\n Updated data : "); list1.displayForward();
                printf("\n Again [Y/N] ? "); scanf("%s", &pil);
			} else if (input_1 == 9) {
				exit(0);
            } else exit(0);
        }
	} else if (type == 2) {
        while ((pil == "Y" || pil == "y" ) && input_1 != 9) {
            system("cls");
            list1.displayForward();
            printf("\n\nDouble Linked List\n");
            printf("========================\n");
            printf("1. Insert an element\n");
            printf("2. Delete an element\n");
            printf("3. Display\n");
            printf("4. Sort\n");
            printf("9. Exit\n");
            printf("What do you want to do with your list? "); scanf("%i", &input_1);
            printf("\n");
            if (input_1 == 1) { // Insert an element
                system("cls");
                list1.displayForward();
                printf("\nSingle Linked List >> Insert\n");
                printf("========================\n");
                printf("1. Insert Front\n");
                printf("2. Insert End\n");
                printf("3. Insert at certain postition\n");
                printf("9. Exit\n");
                printf("Where do you want to insert your element? "); scanf("%i", &input_2);
                printf("\n");
                if (input_2 == 1) { // input front
                    printf("Input your data : "); scanf("%i", &input_2);
                    list1.insertFront(input_2);
                    printf("\n\n Updated data : "); list1.displayForward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                } else if (input_2 == 2) { // input end
                    printf("Input your data : "); scanf("%i", &input_2);
                    list1.insertEnd(input_2);
                    printf("\n\n Updated data : "); list1.displayForward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                } else if (input_2 == 3) { // input at certain position
                    printf("Input your data: "); scanf("%i", &input_2);
                    printf("\nData's position: "); scanf("%i", &pos);
                    list1.insertMiddle(input_2, pos, list1.count());
                    printf("\n\n Updated data : "); list1.displayForward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                }
            } else if (input_1 == 2) { // Delete an element
                system("cls");
                list1.displayForward();
                printf("\nSingle Linked List >> Delete\n");
                printf("========================\n");
                printf("1. Delete Front\n");
                printf("2. Delete End\n");
                printf("3. Delete at certain postition\n");
                printf("9. Exit\n");
                printf("Which element do you want to delete? "); scanf("%i", &input_2);
                printf("\n");
                if (input_2 == 1) { // delete front
                    list1.deleteFront();
                    printf("\n\n Updated data : "); list1.displayForward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                } else if (input_2 == 2) { // delete end
                    list1.deleteEnd();
                    printf("\n\n Updated data : "); list1.displayForward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                } else if (input_2 == 3) { // delete at certain position
                    printf("\nThe postition of the element: "); scanf("%i", &pos);
                    list1.deleteMiddle(pos, list1.count());
                    printf("\n\n Updated data : "); list1.displayForward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                }
            } else if (input_1 = 3) { // display
                system("cls");
                list1.displayForward();
                printf("\nSingle Linked List >> Display\n");
                printf("========================\n");
                printf("1. Display Forward\n");
                printf("2. Display Backward\n");
                printf("9. Exit\n");
                printf("Which one do you like? "); scanf("%i", &input_2);
                printf("\n");
                if (input_2 == 1) { // display forward
                    list1.sort(list1.count());
                    printf("\n\n Updated data : "); list1.displayForward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                } else if (input_2 == 2) { // display backward
                    list1.sort(list1.count());
                    printf("\n\n Updated data : "); list1.displayBackward();
                    printf("\n Again [Y/N] ? "); scanf("%s", &pil);
                }
            } else if (input_1 == 4) { // sort
                list1.sort(list1.count());
                printf("\n\n Updated data : "); list1.displayForward();
                printf("\n Again [Y/N] ? "); scanf("%s", &pil);
			} else if (input_1 == 9) {
				exit(0);
            } else exit(0);
        }
	}
	return 0;
}
