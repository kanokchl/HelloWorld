#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "map.h"

using namespace std;

int main()
    {        
        string command = "START"; 
		
		Map<string, string> map;      
        
		while (command != "QUIT"){
		
			cin >> command;
			
			if (command == "ADD"){
				
				cout << command << endl ;
				
				string Input;
				string Name;
				string Email;
				
				getline(cin, Input);
				
				size_t start = Input.find("[");
				size_t end = Input.find("]");
				
                if (start!=Input.npos){
                	Name = Input.substr(start, end);
				}
				
				size_t start2 = Input.find("[", start + 1);
				size_t end2 = Input.find("]", end + 1);
				
                if (start2!=Input.npos){
                	Email = Input.substr(start2, end2);
				}
				
				cout << Name << endl;
				cout << Email << endl;
				
				//
				
				map.add(Name, Email);
				
			} else if (command == "REMOVE"){
				
				cout << command << endl ;
				
				string Input;
				string Name;
				
				getline(cin, Input);
				
				size_t start = Input.find("[");
				size_t end = Input.find("]");
				
                if (start!=Input.npos){
                	Name = Input.substr(start, end);
				}
				
				
			} else if (command == "QUERY"){
				
				cout << command << endl ;
				
				string Input;
				string Name;
				
				getline(cin, Input);
				
				size_t start = Input.find("[");
				size_t end = Input.find("]");
				
                if (start!=Input.npos){
                	Name = Input.substr(start, end);
				}
					
			} else if (command == "LOAD"){
				
				cout << command << endl ;
				
				ifstream file;
				
				string filename;

             	cin >> filename;

	            file.open(filename.c_str());

				//file.open("hw3q3.txt");
				
				if( !file ){
				    cerr << "File could not be opened." << endl;
                    file.close();
			        return 1;
                }
                
                string Input;
                
                while (getline(file, Input)){
                	
                	string Name;
				    string Email;
				    
				    size_t start = Input.find("[");
				    size_t end = Input.find("]");
				
                    if (start!=Input.npos){
                	    Name = Input.substr(start, end);
				    }
				
				    size_t start2 = Input.find("[", start + 1);
				    size_t end2 = Input.find("]", end + 1);
				
                    if (start2!=Input.npos){
                    	Email = Input.substr(start2, end2);
				    }
				
			    	cout << Name << endl;
				    cout << Email << endl;
                		
                }
                
                file.close();
					
			}
            
		}
        
        return 0;
        
}
