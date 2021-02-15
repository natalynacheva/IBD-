/*#include <iostream>
using namespace std;


typedef int DataType;

typedef struct Node* Po;

struct Node
{
	DataType data;
	Po left;
	Po right;
};

Po root;
void search(int x) {
	Po loc = root;
	Po insert = loc;
	if (root == nullptr)
	{
		loc = new Node;
		loc->data = x;
		loc->left = nullptr;
		loc->right = nullptr;
		root = loc;
		cout << "syzdaden koren";
	}
	else
	{
		loc = root;
		insert = loc;
		while (loc->data != x && loc != nullptr)
		{

			insert = loc;

			if (loc->data > x)
			{
				loc = loc->left;
			}
			else {
				loc = loc->right;
			}
		}
	}
		if (loc->data == x) {
			cout << "nameren elementa - " << x << endl;
		}
		else
		{
			loc = new Node;
			loc->data = x;
			loc->left = nullptr;
			loc->right = nullptr;
			if (insert->data > loc->data)
			{
				insert->left = loc;

			}
			else {

				insert->right = loc;
			}
		}
	}


void print2DUtil(Po root, int space)
{
	int COUNT = 5;
	// Base case  
	if (root == NULL)
		return;

	// Increase distance between levels  
	space += COUNT;

	// Process right child first  
	print2DUtil(root->right, space);

	// Print current node after space  
	// count  
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->data << "\n";

	// Process left child  
	print2DUtil(root->left, space);
}
int main() {
	int x;
	cout << "Vuvedete chislo (ili 0 za da prikluchite): ";
	cin >>x;
	while (x != 0)
	{
		search(x);

		cout << "Vuvedete oshte edno chislo (ili 0 za da prikluchite): ";
		cin >> x;
	}

	print2DUtil(root, 2);

	return 0;
}*/
#include <iostream>
#include <string>
using namespace std;

typedef int dataT;
typedef struct node* Po;
struct node {
	char data;
	Po left;
	Po right;
};
Po root = nullptr;

void treeBuilder(dataT x) {
	Po loc = root;
	Po insert = loc;

	if (root == nullptr)
	{
		loc = new node;
		loc->left = nullptr;
		loc->right = nullptr;
		loc->data = x;
		root = loc;
	}
	else {
		/*
		loc trqbva da spre kogato found == true
		ILI
		loc == nullptr
		*/

		while (loc != nullptr && loc->data != x)
		{
			insert = loc;
			if (loc->data > x)
			{
				loc = loc->left;
			}

			else
			{
				loc = loc->right;
			}

		}
		if (loc != nullptr)
		{
			cout << "Elementyt be nameren!" << endl;
		}
		else {
			loc = new node;
			loc->data = x;
			loc->left = nullptr;
			loc->right = nullptr;

			if (loc->data > insert->data)
			{
				insert->right = loc;

			}
			else {
				insert->left = loc;
			}

		}
	}

}

void print(Po root, int space) {
	int COUNT = 10;
	if (root == nullptr)
		return;

	space += COUNT;
	print(root->right, space);
	std::cout << std::endl;
	for (int i = COUNT; i < space; i++)
		std::cout << " ";
	std::cout << root->data << "\n";
	print(root->left, space);
}

void Infix(Po help)
{
	if (help)
	{
		Infix(help->left);
		cout << help->data << " ";
		Infix(help->right);
	}
}
Po TreeFromSortedArr(int* arr, int beg, int end) {
	
	if (beg <= end) {
		int mid = (beg + end) / 2;
		Po help = new node;
		help->data = arr[mid];
		help->left = nullptr;
		help->right = nullptr;
		
		
		help->left = TreeFromSortedArr(arr, beg,
			mid - 1);

		help->right = TreeFromSortedArr(arr, mid + 1, end);

		return help;
	}else
	{
		return 0;
	}
}


int main() {
	
//zad1
	
	char number;
	cout << "Vuvedete chislo (ili -1 za da prikluchite): ";
	cin >> number;
	while (number != '1')
	{
		treeBuilder(number);

		cout << "Vuvedete oshte edno chislo (ili -1 za da prikluchite): ";
		cin >> number;
	}
/*	int arr[9] = {0,2,4,5,6,9,26,45,96};
	//int end = sizeof(arr)/ sizeof(arr[0]);
	Po root = TreeFromSortedArr(arr, 0, 8);
	*/
	print(root, 5);
	Infix(root);
	return 0;
}

