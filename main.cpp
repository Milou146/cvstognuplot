#include <iostream>
#include <string>
#include <fstream> 

using namespace std;
int main(int argc,char * argv[]){
    //Ouverture du fichier input
    ifstream in_file;
    const char *filename = argv[1];
    string str(filename);
    in_file.open(filename);

    if(in_file.is_open()){
        ofstream out_file;
        cout << filename <<" is opened"<<endl;
        string line;
        int occurrence = 1;
        //lecture ligne a ligne jusque fin du fichier
        out_file.open("output.dat"); 
        if(out_file.is_open()){
            while(!in_file.eof() && line != "\"traffic\",,"){
                getline(in_file, line);
                if(line == "\"Node\",," || line == "\"traffic\",,"){ // on s'arrête juste avant
                    cout << occurrence++ << " : type 1 : " << line << endl;
                }
                else{
                    cout << occurrence++ << " : type 6 : " << line << endl;
                    line.replace(0,7,"",0);
                    if(line.substr(0,3) == "   "){
                        line.replace(0,3,"",0);
                    }
                    else{
                        line.replace(0,1,"",0);
                    }
                    line.replace(2,1,"   ",3);
                    out_file << line << endl;
                }
            }
        }
        //fermeture des fichiers
        out_file.close();
        in_file.close();
        // fichier d'entrée pour gnuplot
        out_file.open("output.in"); 
        out_file << "plot 'output.dat' with lines" << endl;
        out_file.close();
    }else{
        cout << filename <<" is not opened"<<endl;
    }
  return 0;
}