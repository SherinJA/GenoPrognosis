#include<bits/stdc++.h>

#define MAX_CHAR 256
using namespace std;

class SuffixTrieNode
{
private:
	SuffixTrieNode *children[MAX_CHAR];
	list<int> *indexes;
public:
	SuffixTrieNode() // Constructor
	{
		// Create an empty linked list for indexes of suffixes starting from this node
		indexes = new list<int>;

		// Initialize all child pointers as NULL
		for (int i = 0; i < MAX_CHAR; i++)
		children[i] = NULL;
	}

	// A recursive function to insert a suffix of the txt in subtree rooted with this node
	void insertSuffix(string suffix, int index);

	// A function to search a pattern in subtree rooted with this node.
	list<int>* search(string pat);
};

class SuffixTrie
{
private:
	SuffixTrieNode root;
public:
	SuffixTrie(string txt)
	{
		for (int i = 0; i < txt.length(); i++)
			root.insertSuffix(txt.substr(i), i);
	}

	void search(string pat);
};

int foundFlag;

void SuffixTrieNode::insertSuffix(string s, int index)
{
	// Store index in linked list
	indexes->push_back(index);

	// If string has more characters
	if (s.length() > 0)
	{
		// Find the first character
		char cIndex = s.at(0);

		// If there is no edge for this character, add a new edge
		if (children[cIndex] == NULL)
			children[cIndex] = new SuffixTrieNode();

		// Recur for next suffix
		children[cIndex]->insertSuffix(s.substr(1), index+1);
	}
}

list<int>* SuffixTrieNode::search(string s)
{
	// If all characters of pattern have been processed,
	if (s.length() == 0)
		return indexes;

	// If there is an edge from the current node of suffix trie, follow the edge.
	if (children[s.at(0)] != NULL)
		return (children[s.at(0)])->search(s.substr(1));

	// If there is no edge, pattern doesn’t exist in text
	else return NULL;
}

void SuffixTrie::search(string pat)
{
	list<int> *result = root.search(pat);

	if (result == NULL)
		cout << "\n\tPattern not found" << endl;
	else
	{
		list<int>::iterator i;
		int patLen = pat.length();
		foundFlag = 1;
		cout<<"\n\tMATCH FOUND !!"<<endl;
		for (i = result->begin(); i != result->end(); ++i)
			cout << "\n\tPattern found at position " << *i - patLen;
	}
}

int main()
{
    ifstream fp;
    fp.open("persons.txt");

    if(!fp.is_open())
        exit(EXIT_FAILURE);

    string filename, pattern;
    fp>>filename;

	cout<<"\n\t************************************************************"<<endl;
	cout<<"\n\t\t\t\tDNA Sequence Matching"<<endl;
	cout<<"\n\t************************************************************"<<endl;

	cout<<"\n\tNOTE: Enter a pattern of more than 10 nucleotides for better approximation.";
	while(1)
	{
		int flag=0;
		cout<<"\n\n\tEnter a pattern to search: ";
		cin>>pattern;
		int len;
		len=pattern.length();
		transform(pattern.begin(), pattern.end(), pattern.begin(), ::toupper);
		//cout<<pattern<<endl;
		for(int i=0;i<len;i++)
		{
			if(pattern[i]=='A'|| pattern[i]=='C'|| pattern[i]=='G'||pattern[i]=='T')
			{
				continue;
			}
			else
			{
				flag=1;
				cout<<"\n\n\n\t\t\tINVALID INPUT! RE-ENTER!";
				break;
			}
		}
		if(flag==0)
		{
			break;
		}

	}
	
	int i = 1;
    while(!fp.eof())
    {
		ifstream f;
		f.open(filename);
		string str, disease;
		foundFlag = 0;

		if(!f.eof()) 
		{
      		f>>str;
			f>>disease;
   		}
		cout<<"\n\tTest sample "<<i++<<":-";
		SuffixTrie S(str);

		S.search(pattern);

		if(foundFlag == 1)
			cout<<"\n\n\t\tPredicted disease: "<<disease<<endl;

        fp>>filename;
		f.close();
	}
	fp.close();

	cout<<"\n\tComparing among samples in database:-"<<endl;
	int personChoice = 0;

	cout<<"\n\tEnter person no. to compare with others: ";
	cin>>personChoice;

	ifstream f;
	string str, disease;
	fp.open("persons.txt");
	switch (personChoice)
	{
	case 1:
		f.open("person1.txt");
		f>>pattern;
		pattern = pattern.substr(0, 20);
		f.close();
		while(!fp.eof())
    	{
		fp>>filename;

		if (filename == "person1.txt")
		{
			continue;
		}
		f.open(filename);
		foundFlag = 0;

		if(!f.eof()) 
		{
      		f>>str;
			f>>disease;
   		}
		cout<<"\n\tTest sample "<<filename;
		SuffixTrie S(str);

		S.search(pattern);

		if(foundFlag == 1)
			cout<<"\n\n\t\tPredicted disease: "<<disease<<endl;

		
		f.close();
		}

	case 2:
		f.open("person2.txt");
		f>>pattern;
		pattern = pattern.substr(0, 20);
		f.close();
		while(!fp.eof())
    	{
		fp>>filename;

		if (filename == "person2.txt")
		{
			continue;
		}
		f.open(filename);
		foundFlag = 0;

		if(!f.eof()) 
		{
      		f>>str;
			f>>disease;
   		}
		cout<<"\n\tTest sample "<<filename;
		SuffixTrie S(str);

		S.search(pattern);

		if(foundFlag == 1)
			cout<<"\n\n\t\tPredicted disease: "<<disease<<endl;

		f.close();
		}

	case 3:
		f.open("person3.txt");
		f>>pattern;
		pattern = pattern.substr(0, 20);
		f.close();
		while(!fp.eof())
    	{
		fp>>filename;
		
		if (filename == "person3.txt")
		{
			continue;
		}
		f.open(filename);
		foundFlag = 0;

		if(!f.eof()) 
		{
      		f>>str;
			f>>disease;
   		}
		cout<<"\n\tTest sample "<<filename;
		SuffixTrie S(str);

		S.search(pattern);

		if(foundFlag == 1)
			cout<<"\n\n\t\tPredicted disease: "<<disease<<endl;

		f.close();
		}

	case 4:
		f.open("person4.txt");
		f>>pattern;
		pattern = pattern.substr(0, 20);
		f.close();
		while(!fp.eof())
    	{
		fp>>filename;

		if (filename == "person4.txt")
		{
			continue;
		}
		f.open(filename);
		foundFlag = 0;

		if(!f.eof()) 
		{
      		f>>str;
			f>>disease;
   		}
		cout<<"\n\tTest sample "<<filename;
		SuffixTrie S(str);

		S.search(pattern);

		if(foundFlag == 1)
			cout<<"\n\n\t\tPredicted disease: "<<disease<<endl;

		f.close();
		}

	case 5:
		f.open("person5.txt");
		f>>pattern;
		pattern = pattern.substr(0, 20);
		f.close();
		while(!fp.eof())
    	{
		fp>>filename;

		if (filename == "person5.txt")
		{
			continue;
		}
		f.open(filename);
		foundFlag = 0;

		if(!f.eof()) 
		{
      		f>>str;
			f>>disease;
   		}
		cout<<"\n\tTest sample "<<filename;
		SuffixTrie S(str);

		S.search(pattern);

		if(foundFlag == 1)
			cout<<"\n\n\t\tPredicted disease: "<<disease<<endl;

		f.close();
		}

	case 6:
		f.open("person6.txt");
		f>>pattern;
		pattern = pattern.substr(0, 20);
		f.close();
		while(!fp.eof())
    	{
		fp>>filename;

		if (filename == "person6.txt")
		{
			continue;
		}
		f.open(filename);
		foundFlag = 0;

		if(!f.eof()) 
		{
      		f>>str;
			f>>disease;
   		}
		cout<<"\n\tTest sample "<<filename;
		SuffixTrie S(str);

		S.search(pattern);

		if(foundFlag == 1)
			cout<<"\n\n\t\tPredicted disease: "<<disease<<endl;

		f.close();
		}

	case 7:
		f.open("person7.txt");
		f>>pattern;
		pattern = pattern.substr(0, 20);
		f.close();
		while(!fp.eof())
    	{
		fp>>filename;

		if (filename == "person7.txt")
		{
			continue;
		}
		f.open(filename);
		foundFlag = 0;

		if(!f.eof()) 
		{
      		f>>str;
			f>>disease;
   		}
		cout<<"\n\tTest sample "<<filename;
		SuffixTrie S(str);

		S.search(pattern);

		if(foundFlag == 1)
			cout<<"\n\n\t\tPredicted disease: "<<disease<<endl;

		f.close();
		}

	case 8:
		f.open("person8.txt");
		f>>pattern;
		pattern = pattern.substr(0, 20);
		f.close();
		while(!fp.eof())
    	{
		fp>>filename;

		if (filename == "person8.txt")
		{
			continue;
		}
		f.open(filename);
		foundFlag = 0;

		if(!f.eof()) 
		{
      		f>>str;
			f>>disease;
   		}
		cout<<"\n\tTest sample "<<filename;
		SuffixTrie S(str);

		S.search(pattern);

		if(foundFlag == 1)
			cout<<"\n\n\t\tPredicted disease: "<<disease<<endl;

		f.close();
		}

	/*case 9:
		f.open("person9.txt");
		f>>pattern;
		pattern = pattern.substr(0, 20);
		f.close();
		while(!fp.eof())
    	{
		fp>>filename;

		if (filename == "person9.txt")
		{
			continue;
		}
		f.open(filename);
		foundFlag = 0;

		if(!f.eof()) 
		{
      		f>>str;
			f>>disease;
   		}
		cout<<"\n\tTest sample "<<filename;
		SuffixTrie S(str);

		S.search(pattern);

		if(foundFlag == 1)
			cout<<"\n\n\t\tPredicted disease: "<<disease<<endl;

		f.close();
		}

	case 10:
		f.open("person10.txt");
		f>>pattern;
		pattern = pattern.substr(0, 20);
		f.close();
		while(!fp.eof())
    	{
		fp>>filename;

		if (filename == "person10.txt")
		{
			continue;
		}
		f.open(filename);
		foundFlag = 0;

		if(!f.eof()) 
		{
      		f>>str;
			f>>disease;
   		}
		cout<<"\n\tTest sample "<<filename;
		SuffixTrie S(str);

		S.search(pattern);

		if(foundFlag == 1)
			cout<<"\n\n\t\tPredicted disease: "<<disease<<endl;

		f.close();
		}*/
	default:
		break;
	}
}