#include <iostream>
#include <string>
#include <fstream> 

using namespace std;
int main(int argc,char * argv[]){
    // opening input files
    ifstream in_file;
    const char *filename = argv[1];
    string str(filename);
    in_file.open(filename);

    if(in_file.is_open()){
        cout << filename <<" is opened"<< endl;
        ofstream out_dat_file;
        ofstream out_dem_file;
        string line;
        int occurrence = 1;
        out_dat_file.open("output.dat");
        out_dem_file.open("output.dem");
        // line-by-line reading until end of file
        if(out_dat_file.is_open() && out_dem_file.is_open()){
            cout << "output.dem or output.dat is opened"<<endl;
            while(!in_file.eof() && line != "\"traffic\",,"){
                getline(in_file, line);
                if(line == "\"Node\",," || line == "\"traffic\",,"){
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
                    out_dat_file << line << endl;
                }
            }
        }
        else{
            cout << "output.dem or output.dat is not opened"<<endl;
        }
        // closing files
        out_dat_file.close();
        in_file.close();
        // gnuplot output file
        out_dem_file << "plot 'output.dat' with lines" << endl;
        out_dem_file << "pause -1 \" (-> return)\"" << endl;
        out_dem_file.close();
    }else{
        cout << filename <<" is not opened"<<endl;
    }
  return 0;
}