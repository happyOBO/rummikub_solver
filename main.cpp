#include <iostream>
#include <vector>
#include <utility> // pair
#include <bitset>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int num_of_red_tiles,num_of_yellow_tiles,num_of_black_tiles,num_of_blue_tiles;
    vector<int> red_tiles;
    vector<int> yellow_tiles;
    vector<int> black_tiles;
    vector<int> blue_tiles;
    cout<<
    " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.\n"<<
    "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n"<<
    "| |  _______     | || | _____  _____ | || | ____    ____ | || | ____    ____ | || |     _____    | || |     ______   | || | _____  _____ | || |   ______     | || |  _________   | |\n"<<
    "| | |_   __ \\    | || ||_   _||_   _|| || ||_   \\  /   _|| || ||_   \\  /   _|| || |    |_   _|   | || |   .' ___  |  | || ||_   _||_   _|| || |  |_   _ \\    | || | |_   ___  |  | |\n"<<
    "| |   | |__) |   | || |  | |    | |  | || |  |   \\/   |  | || |  |   \\/   |  | || |      | |     | || |  / .'   \\_|  | || |  | |    | |  | || |    | |_) |   | || |   | |_  \\_|  | |\n"<<
    "| |   |  __ /    | || |  | '    ' |  | || |  | |\\  /| |  | || |  | |\\  /| |  | || |      | |     | || |  | |         | || |  | '    ' |  | || |    |  __'.   | || |   |  _|  _   | |\n"<<
    "| |  _| |  \\ \\_  | || |   \\ `--' /   | || | _| |_\\/_| |_ | || | _| |_\\/_| |_ | || |     _| |_    | || |  \\ `.___.'\\  | || |   \\ `--' /   | || |   _| |__) |  | || |  _| |___/ |  | |\n"<<
    "| | |____| |___| | || |    `.__.'    | || ||_____||_____|| || ||_____||_____|| || |    |_____|   | || |   `._____.'  | || |    `.__.'    | || |  |_______/   | || | |_________|  | |\n"<<
    "| |              | || |              | || |              | || |              | || |              | || |              | || |              | || |              | || |              | |\n"<<
    "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n"<<
    " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'\n"<<endl;
    cout<<
    "                                 .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.\n"<<
    "                                | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n"<<
    "                                | |    _______   | || |     ____     | || |   _____      | || | ____   ____  | || |  _________   | || |  _______     | |\n"<<
    "                                | |   /  ___  |  | || |   .'    `.   | || |  |_   _|     | || ||_  _| |_  _| | || | |_   ___  |  | || | |_   __ \\    | |\n"<<
    "                                | |  |  (__ \\_|  | || |  /  .--.  \\  | || |    | |       | || |  \\ \\   / /   | || |   | |_  \\_|  | || |   | |__) |   | |\n"<<
    "                                | |   '.___`-.   | || |  | |    | |  | || |    | |   _   | || |   \\ \\ / /    | || |   |  _|  _   | || |   |  __ /    | |\n"<<
    "                                | |  |`\\____) |  | || |  \\  `--'  /  | || |   _| |__/ |  | || |    \\ ' /     | || |  _| |___/ |  | || |  _| |  \\ \\_  | |\n"<<
    "                                | |  |_______.'  | || |   `.____.'   | || |  |________|  | || |     \\_/      | || | |_________|  | || | |____| |___| | |\n"<<
    "                                | |              | || |              | || |              | || |              | || |              | || |              | |\n"<<
    "                                | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n"<<
    "                                 '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'\n"<<endl;

    cout<<"Write Your Tiles"<<endl;
    cout<<"# of Received Red Tiles (ex: 5): ";
    cin>>num_of_red_tiles;
    cout<<"Received Red Tiles (ex: 1 3 5): ";
    for(int i = 0; i < num_of_red_tiles; i++)
    {
        int tile;
        cin>>tile;
        red_tiles.push_back(tile);
    }
    cout<<"# of Received Yellow Tiles (ex: 5): ";
    cin>>num_of_yellow_tiles;
    cout<<"Received Yellow Tiles (ex: 1 3 5): ";
    for(int i = 0; i < num_of_yellow_tiles; i++)
    {
        int tile;
        cin>>tile;
        yellow_tiles.push_back(tile);
    }
    cout<<"# of Received Black Tiles (ex: 5): ";
    cin>>num_of_black_tiles;
    cout<<"Received Black Tiles (ex: 1 3 5): ";
    for(int i = 0; i < num_of_black_tiles; i++)
    {
        int tile;
        cin>>tile;
        black_tiles.push_back(tile);
    }
    cout<<"# of Received Blue Tiles (ex: 5): ";
    cin>>num_of_blue_tiles;
    cout<<"Received Blue Tiles (ex: 1 3 5): ";
    for(int i = 0; i < num_of_blue_tiles; i++)
    {
        int tile;
        cin>>tile;
        blue_tiles.push_back(tile);
    }
    cout<<"The Tiles You Got"<<endl;
    cout<<"================="<<endl;
    if(14 == (num_of_red_tiles + num_of_yellow_tiles + num_of_black_tiles + num_of_blue_tiles))
    {
        for(int i = 0; i<14;i++)
        {
            if(i < num_of_red_tiles)
            {
                if(i == 0)
                {
                    cout<<"\nRed Tiles : ";
                }
                
                cout<<red_tiles[i]<<" ";
            }
            else if(i < num_of_red_tiles + num_of_yellow_tiles)
            {
                if(i == num_of_red_tiles)
                {
                    cout<<"\nYellow Tiles : ";
                }
                
                cout<<yellow_tiles[i-num_of_red_tiles]<<" ";
            }
            else if(i < num_of_red_tiles + num_of_yellow_tiles + num_of_black_tiles)
            {
                if(i == (num_of_red_tiles + num_of_yellow_tiles))
                {
                    cout<<"\nBlack Tiles : ";
                }
                
                cout<<black_tiles[i-(num_of_red_tiles + num_of_yellow_tiles)]<<" ";
            }
            else
            {
                if(i == (num_of_red_tiles + num_of_yellow_tiles + num_of_black_tiles))
                {
                    cout<<"\nBlue Tiles : ";
                }
                
                cout<<blue_tiles[i-(num_of_red_tiles + num_of_yellow_tiles + num_of_black_tiles)]<<" ";
            }
        }
    }
    else
    {
        cout<<"You typed it wrong. Retry."<<endl;
    }
}