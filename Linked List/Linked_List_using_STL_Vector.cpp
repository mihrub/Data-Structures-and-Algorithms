#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void display(){
    cout << endl << "** Linked List **" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Update" << endl;
    cout << "4. Search" << endl;
    cout << "5. Front" << endl;
    cout << "6. Back" << endl;
    cout << "7. Print" << endl;
    cout << "8. Clear" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your option : ";    
}

void insert_display(){
    cout << "1.Push Front " << endl;
    cout << "2.Push Back" << endl;
    cout << "Enter your option : ";    
}

void delete_display(){
    cout << "1.Pop Front" << endl;
    cout << "2.Pop Back" << endl;
    cout << "Enter your option : ";    
}

int main(){
      
    vector<int> vec;

    while(true){
        display();
        int option;
        cin >> option;

        switch(option){
            case 1:{
                int x,value;
                insert_display();
                cin >> x;
                cout << "Enter a Value : ";
                cin >> value;

                if(x == 1){
                    vec.insert(vec.begin(),value);
                }
                else if(x == 2){
                    vec.push_back(value);
                }
                else{
                    cout << "Enter Correctly" << endl;
                }

                cout << "Element Pushed" << endl;
                break;
            }
            case 2:{
                int length = vec.size();
                if(length == 0){
                    cout << "Nothing To Pop" << endl;
                }
                else{
                int x;
                delete_display();
                cin >> x;

                if(x == 1){
                    vec.erase(vec.begin());
                }
                else if(x == 2){
                    vec.pop_back();
                }
                else{
                    cout << "Enter Correctly" << endl;
                }
                cout << "Element Popped" << endl;
            }
                break;
            }
            case 3:{
                int length = vec.size();
                cout << "Size : " << length << endl;
                int position,value;
                cout << "Position : ";
                cin >> position;
                cout << "Value : ";
                cin >> value;

                if(position > length){
                cout << "Invalid Operation" << endl;    
                }
                else{
                vec[position] = value;
                }
                break;
            }
            case 4:{
                int x;
                cout << "Enter Value : ";
                cin >> x;

                auto it = find(vec.begin(),vec.end(),x);

                if(it == vec.end()){
                    cout << "Not Found" << endl;
                }
                else{
                    cout << "Found" << endl;
                }
                break;
            }
            case 5:{
                cout << "Front : " << vec.front() << endl;
                break;
            }
            case 6:{
                cout << "Back : " << vec.back() << endl;
                break;
            }
            case 7:{
                for(int x : vec){
                    cout << x << " ";
                }
                cout << endl;
                break;
            }
            case 8:{
                cout << "Clearing All Elements" << endl;
                vec.clear();
                int length = vec.size();
                cout << "Size : " << length << endl;
                break;
            }
            case 9:
                cout << "Exiting....." << endl;
                exit(0);
                break;
            default:
                cout << "Enter Between (1-9) !" << endl;
        }
    }    
    return 0;
}