#include <iostream>
#include <vector>
#include <utility> // pair
#include <bitset>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>


#define BLACK 7
#define BLUE 46
#define RED 41
#define YELLOW 43


using namespace std;
void error_msg();

int num_of_red_tiles,num_of_yellow_tiles,num_of_black_tiles,num_of_blue_tiles;
map<int,int> red_tiles;
map<int,int> blue_tiles;
map<int,int> yellow_tiles;
map<int,int> black_tiles;


void show_ascii_art(void)
{
    cout<<
    " ____                                _               _             ____          _                    \n"<<
    "|  _ \\  _   _  _ __ ___   _ __ ___  (_)  ___  _   _ | |__    ___  / ___|   ___  | |__   __  ___  _ __ \n"<<
    "| |_) || | | || '_ ` _ \\ | '_ ` _ \\ | | / __|| | | || '_ \\  / _ \\ \\___ \\  / _ \\ | |\\ \\ / / / _ \\| '__|\n"<<
    "|  _ < | |_| || | | | | || | | | | || || (__ | |_| || |_) ||  __/  ___) || (_) || | \\ V / |  __/| |   \n"<<
    "|_| \\_\\ \\__,_||_| |_| |_||_| |_| |_||_| \\___| \\__,_||_.__/  \\___| |____/  \\___/ |_|  \\_/   \\___||_|   "<<endl;
    cout<<
    "\n                         ____ ____ _  _ ____    ____ ___ ____ ____ ___ \n"<<
    "                         | __ |__| |\\/| |___    [__   |  |__| |__/  |  \n"<<
    "                         |__] |  | |  | |___    ___]  |  |  | |  \\  | \n"<<endl;
}

void init(void)
{
    try
    {
   
        for(int i = 1; i<= 13; i++)
        {
            red_tiles.insert(make_pair(i, 0));
            yellow_tiles.insert(make_pair(i, 0));
            black_tiles.insert(make_pair(i, 0));
            blue_tiles.insert(make_pair(i, 0));
        }

        cout<<"Write down the tiles you have.\n"<<endl;
        cout<<"# of Received Red Tiles (ex: 5): ";
        cin>>num_of_red_tiles;
        cout<<"Received Red Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_red_tiles; i++)
        {
            int tile;
            cin>>tile;
            red_tiles[tile]++;
        }

        cout<<"# of Received Blue Tiles (ex: 5): ";
        cin>>num_of_blue_tiles;
        cout<<"Received Blue Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_blue_tiles; i++)
        {
            int tile;
            cin>>tile;
            if(tile > 13) error_msg();
            blue_tiles[tile]++;
        }

        cout<<"# of Received Yellow Tiles (ex: 5): ";
        cin>>num_of_yellow_tiles;
        cout<<"Received Yellow Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_yellow_tiles; i++)
        {
            int tile;
            cin>>tile;
            if(tile > 13) error_msg();
            yellow_tiles[tile]++;
        }
        
        cout<<"# of Received Black Tiles (ex: 5): ";
        cin>>num_of_black_tiles;
        cout<<"Received Black Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_black_tiles; i++)
        {
            int tile;
            cin>>tile;
            if(tile > 13) error_msg();
            black_tiles[tile]++;
        }
    }
    catch(int err)
    {
        error_msg();
    }
 
}

void print_user_tiles()
{
    char string_tiles[20][20] = {"NONE","|1 |","|2 |","|3 |","|4 |","|5 |","|6 |","|7 |","|8 |","|9 |", "|10|" ,"|11|","|12|","|13|"}; 
    try
    {
        for(int j = 0; j < num_of_red_tiles; j++)
        {
            printf("\033[%dm%s\033[0m  ",RED, ".___");
        }
        cout<<endl;
        for(int i = 1; i<= 13; i++)
        {
            if(red_tiles[i] != 0)
            {
                for(int j = 0; j < red_tiles[i]; j++)
                {
                    printf("\033[%dm%s\033[0m  ",RED, string_tiles[i]);
                }

            }
            
        }
        cout<<endl;
        for(int j = 0; j < num_of_red_tiles; j++)
        {
            printf("\033[%dm%s\033[0m  ",RED, "|__|");
        }
        cout<<endl;

        for(int j = 0; j < num_of_blue_tiles; j++)
        {
            printf("\033[%dm%s\033[0m  ", BLUE, ".___");
        }
        cout<<endl;
        for(int i = 1; i<= 13; i++)
        {
            if(blue_tiles[i] != 0)
            {

                for(int j = 0; j < blue_tiles[i]; j++)
                {
                    printf("\033[%dm%s\033[0m  ", BLUE, string_tiles[i]);
                }
            }    
        }
        cout<<endl;
        for(int j = 0; j < num_of_blue_tiles; j++)
        {
            printf("\033[%dm%s\033[0m  ", BLUE, "|__|");
        }

        cout<<endl;


        for(int j = 0; j < num_of_yellow_tiles; j++)
        {
            printf("\033[%dm%s\033[0m  ", YELLOW, ".___");
        }
        cout<<endl;
        for(int i = 1; i<= 13; i++)
        {
            if(yellow_tiles[i] != 0)
            {
                for(int j = 0; j < yellow_tiles[i]; j++)
                {
                    printf("\033[%dm%s\033[0m  ", YELLOW, string_tiles[i]);
                }
            }
        }
        cout<<endl;
        for(int j = 0; j < num_of_yellow_tiles; j++)
        {
            printf("\033[%dm%s\033[0m  ", YELLOW, "|__|");
        }

        cout<<endl;
        for(int j = 0; j < num_of_black_tiles; j++)
        {
            printf("\033[%dm%s\033[0m  ",BLACK,  ".___");
        }
        cout<<endl;
        for(int i = 1; i<= 13; i++)
        {
            if(black_tiles[i] != 0)
            {
                for(int j = 0; j < black_tiles[i]; j++)
                {
                    printf("\033[%dm%s\033[0m  ",BLACK, string_tiles[i]);
                }
            }
        } 
        cout<<endl;
        for(int j = 0; j < num_of_black_tiles; j++)
        {
            printf("\033[%dm%s\033[0m  ",BLACK, "|__|");
        }
        cout<<endl;
    }
    catch(int err)
    {
        error_msg();
    }

}

void error_msg()
{
    cout<<
    "\n_   _ ____ _  _    ___ _   _ ___  ____ ___     _ ___    _ _ _ ____ ____ _  _ ____     ____ ____ ___ ____ _   _  \n"<<
    " \\_/  |  | |  |     |   \\_/  |__] |___ |  \\    |  |     | | | |__/ |  | |\\ | | __     |__/ |___  |  |__/  \\_/   \n"<<
    "  |   |__| |__|     |    |   |    |___ |__/    |  |     |_|_| |  \\ |__| | \\| |__] .   |  \\ |___  |  |  \\   |   .\n"<<endl;
}

int main(void)
{
    show_ascii_art();
    init();
    int num_of_total_tiles = num_of_red_tiles + num_of_yellow_tiles + num_of_blue_tiles + num_of_black_tiles;
    if (num_of_total_tiles == 14)
    {
        print_user_tiles();
    }
    else
    {
        error_msg();
    }
    
    
}