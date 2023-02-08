#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class Board
{
private:
    vector<vector<char>> map_;
    int dimX_, dimY_;

public:
    Board(int dimX_ = 99, int dimY_ = 99);
    void init(int dimX, int dimY);
    void display(int dimX, int dimY);
    int getDimX();
    int getDimY();
    char getObject(int x, int y) const;
    void setObject(int x, int y, char ch);  
};

int test()
{
    return 0;
}

class Alien
{
private:
    int AlienId;    // A
    int Alien_xPos; // rows
    int Alien_yPos; // columns
public:
    Alien();
    void setAlien(Board &board);
    int getxPos() const;
    int getyPos() const;
    void moveUp(Board &board);
    void moveDown(Board &board, int dimY);
    void moveLeft (Board &board);
    void moveRight(Board &board, int &columns);
    // int alienLife;
    // int alienAttack;
    // int A_life();
    // int A_attack();
    // int A_range();
    // void generateAlienProperties(int &life, int &attack, int &range);
    // void generateZombies(int &numOfZombies, int &rows, int &columns, std::string **arr, int **placeZombie);
};
int test()
{
    return 0;
}
class Zombie
{
private:
    vector<int> numOfZombies{};
    vector<int> zombieLife{};
    vector<int> zombieAttack{};
    vector<int> zombieRange{};

public:
    int id;
    int life;
    int attack;
    int range;
    int number;
    int xPos;
    int yPos;
    const int minLife = 10;
    const int maxLife = 50;
    const int minAttack = 1;
    const int maxAttack = 10;
    const int minRange = 1;
    const int maxRange = 5;
    const int maxZombie = 4;
    void assignZombies(Board &board,int &zombies);
};

// board
int Board::getDimX()
{
    return dimX_;
}

int Board::getDimY()
{
    return dimY_;
}

Board::Board(int dimX, int dimY)
{
    init(dimX, dimY);
}

void Board::init(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', 'h', '>', 'r', 'p', '<', '^', 'v'};
    int noOfObjects = 13; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}

void alienAttribute()
{
    int alienLife = 100;
    int alienAttack = 0;
    cout << endl;
    cout << "-> Alien    : Life  " << alienLife << ", Attack  " << alienAttack << endl; 
}

void zombieAttribute(int zombie)
{
    int z;
    int zombieLife = 100;
    int range = 0;
    for(z = 1; z <= zombie; z++)
    {
        cout << "Zombie"<< z <<  "-> Life: " << zombieLife << ", range: " << range << endl;
    }
}

void Board::display(int dimX, int dimY)
{
    int zombie;
    dimX_ = dimX;
    dimY_ = dimY;
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    cout << " -------------------------------" << endl;
    cout << " =        Alien VS Zombie      =" << endl;
    cout << " -------------------------------" << endl;
    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (i + 1);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j) // j==0...14
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl;
    alienAttribute();
    zombieAttribute(zombie);
}

char Board::getObject(int x, int y) const
{
    return map_[-(y - 5)][x - 1];
}

void Board::setObject(int x, int y, char ch)
{
    map_[dimY_ - y][x - 1] = ch;
}

// alien
Alien::Alien()
{
}


void Alien::setAlien(Board &board)
{
    char AlienId = 'A';
    Alien_xPos = ((board.getDimX() + 1) / 2);
    Alien_yPos = ((board.getDimY() + 1) / 2);
    board.setObject(Alien_xPos, Alien_yPos, AlienId);
}

int Alien::getxPos() const
{
    return Alien_xPos;
}

int Alien::getyPos() const
{
    return Alien_yPos;
}

void Alien::moveUp(Board &board)
{
    if (Alien_yPos + 1 > 0)
    {  
        // int upY = board.getDimY();
        int upY = Alien_yPos + 1;
        board.setObject(Alien_xPos, upY, 'A');
        board.setObject(Alien_xPos,Alien_yPos,'.');
        Alien_yPos = upY;
    }

    //system("pause");
    //system("cls");
}

void Alien::moveDown(Board &board, int dimY)
{
    if (Alien_yPos + 1 < dimY - 1)
    {  
        int downY = Alien_yPos - 1;
        board.setObject(Alien_xPos, downY, 'A');
        board.setObject(Alien_xPos,Alien_yPos,'.');
        Alien_yPos = downY;
    }
    //system("pause");
    //system("cls");
}

void Alien::moveRight(Board &board, int &columns)
{
    if (Alien_xPos + 1 <= columns)
    {  
        //int rightX = board.getDimX();
        int rightX = Alien_xPos + 1;
        board.setObject(rightX, Alien_yPos, 'A');
        board.setObject(Alien_xPos,Alien_yPos,'.');
        Alien_xPos = rightX;
    }
    //system("pause");
    //system("cls");
}

void Alien::moveLeft(Board &board)
{
    if (Alien_xPos - 1 > 0)
    {   
        //int leftX = board.getDimX();
        int leftX = Alien_xPos - 1;
        board.setObject(leftX, Alien_yPos, 'A');
        board.setObject(Alien_xPos,Alien_yPos,'.');
        Alien_xPos = leftX;
    }
    //system("pause");
    //system("cls");
}


// void generateZombies(int &numOfZombies, int &rows, int &columns, string **arr, int **placeZombie) {
//     for (int i = 0; i < numOfZombies; ++i) {
//         Zombie z;
//         z.number = i;
//         z.life = randLife();
//         z.attack = randAttack();
//         z.range = randRange();
//         int randRow, randColumn;
//         do {
//             randRow = rand() % rows;
//             randColumn = rand() % columns;
//         } while (arr[randRow][randColumn] != ".");
//         z.xPos = randRow;
//         z.yPos = randColumn;
//         arr[randRow][randColumn] = to_string(i+1);
//         zombies.push_back(z);
//     }
// }

void displayDefaultSetting(int &rows, int &columns, int &zombie)
{
    //system("cls");
    cout << "Default Game Settings" << endl;
    cout << "---------------------" << endl;
    cout << "Board Rows        : " << rows << endl;
    cout << "Board Columns     : " << columns << endl;
    cout << "Zombie Count      : " << zombie << endl;

    cout << "Do you wish to change the game settings (y/n)? => ";
}
int newSetting(int &rows, int &columns, int &zombie)
{
    //system("cls");
    cout << "Change Board Settings " << endl;
    cout << "---------------------" << endl;
    // rows
    do
    {
        cout << "Enter Rows        : ";
        cin >> rows;
        if (rows % 2 == 0 || rows < 3 || rows > 99)
            cout << "Try enter odd integer larger than 2" << endl;

    } while (rows % 2 == 0 || rows < 3);
    // columns
    do
    {
        cout << "Enter Columns     : ";
        cin >> columns;
        if (columns % 2 == 0 || columns < 3 || columns > 99)
            cout << "Try enter odd integer larger than 2" << endl;

    } while (columns % 2 == 0 || columns < 3);
    // zombie
    cout << "Change Zombie Settings   " << endl;
    cout << "-------------------------" << endl;
    do
    {
        cout << "Enter number of zombie        : ";
        cin >> zombie;
        if (zombie < 1 || zombie > 4)
            cout << "Try enter integer in range 1 to 4" << endl;

    } while (zombie < 1 || zombie > 4);
    return rows, columns, zombie;
}

// zombies
vector<Zombie> zombies;

// Generates a random number within the specified range
int randomNumber(int min, int max)
{
    return min + (rand() % (int)(max - min + 1));
}

int randomLife() //zombie life
{
    int finalLife;
    int life[4] = {100, 150, 200, 250};
    finalLife = life[rand() % 4];
    return finalLife;
}

int randAttack() //zombie attack
{
    int finalAttack;
    int attack[4] = {0, 5, 10, 15};
    finalAttack = attack[rand() % 4];
    return finalAttack;
}

int randomRange() //zombie range
{
    int finalRange;
    int range[4] = {1, 2, 3, 4};
    finalRange = range[rand() % 4];
    return finalRange;    
}

// Initializes the attributes of the zombies
void Zombie::assignZombies(Board &board, int &zombie)
{
    
    for (int i = 0; i < zombie; i++)
    {
        vector<char> zchar{'1','2','3','4'};
        Zombie z;
        xPos = rand()% board.getDimX();
        yPos = rand()% board.getDimY();
        z.id = i + 1;
        z.life = randomNumber(minLife, maxLife);
        z.attack = randomNumber(minAttack,maxAttack);
        z.range = randomNumber(minRange, maxRange);
        board.setObject(xPos, yPos, zchar[i]);
        zombies.push_back(z);
    }
}

// Command
void saveGame()
{

}

void loadGame()
{

}

void displayHelp()
{
    cout << "Commands" << endl;
    cout << "1. up    - Move up. " << endl;
    cout << "2. down  - Move down. " << endl;
    cout << "3. left  - Move left. " << endl;
    cout << "4. right - Move right. " << endl;
    cout << "5. arrow - Change the direction of an arrow. " << endl;
    cout << "6. help  - Display these user commands. " << endl;
    cout << "7. save  - Save the game. " << endl;
    cout << "8. load  - Load a game. " << endl;
    cout << "9. quit  - Quit game. " << endl;
}

void displayGame(int &rows, int &columns, int &zombie)
{
    Alien alien;
    Zombie zombies;
    Board board(columns, rows);
    int dimX;
    int dimY;
    alien.setAlien(board);
    zombies.assignZombies(board, zombie);
    board.display(columns, rows);
    // alienAttribute();
    bool quit = false;
    string command;

    do
    {
        cout << endl;
        cout<<"Command ->";
        cin >> command; 
        if(command=="up")
        {
            alien.moveUp(board);
            board.display(columns,rows);
        }
        else if (command == "down")
        {
            alien.moveDown(board, dimY);
            board.display(columns,rows);
        }
        else if (command == "left")
        {
            alien.moveLeft(board);
            board.display(columns,rows);
        }
        else if (command == "right")
        {
            alien.moveRight(board, columns);
            board.display(columns,rows);
        }
        else if (command == "arrow")
        {

        }
        else if (command == "help")
        {
            displayHelp();
            // system("cls");
            cout << endl;
            // displayCommand(rows, columns, zombie);
        }
        else if (command == "save")
        {
            
        }
        else if (command == "load")
        {
            
        }
        else if (command == "quit")
        {
            quit = true;
            cout << "GOOD BYE!!" << endl;
            //system("pause");
            //system("cls");
        }
        else
        {
            cout << "Invalid selection, please try again!" << endl;
            cout << "You can view the help command by entering 'help'. " << endl;
            cout << endl;
        }
    }while (!quit);
}  

// main
int main()
{
    Board board;
    Zombie zombies;
    int rows = 5;
    int columns = 9;
    int zombie = 1;
    char choice;
    char choose;
    bool done = false;
    string **arr;  
    srand(time(NULL));
    do
    {
        cout << " _______________________" << endl;
        cout << "|   Alien vs. Zombie    |" << endl;
        cout << "|-----------------------|" << endl;
        cout << "| Select:               |" << endl;
        cout << "| 1 => Start Game       |" << endl;
        cout << "| 2 => Settings         |" << endl;
        cout << "|-----------------------|" << endl;
        cout << "| Q => Quit             |" << endl;
        cout << "|_______________________|" << endl;
        cout << endl;
        cout << "choice => ";
        cin >> choice;
        choice = toupper(choice);
        cout << endl;
        //system("cls");
        switch (choice)
        {
        case '1':
            displayGame(rows, columns, zombie);
            cout << endl;
            // generateZombies(zombie, rows, columns, arr, placeZombie);
            break;
        case '2':
            displayDefaultSetting(rows, columns, zombie);
            cin >> choose;
            cout << endl;
            if (choose == 'y' || choose == 'Y')
            {
                newSetting(rows, columns, zombie);
                cout << endl;
                cout << "Settings Updated. " << endl;
                cout << endl;
                //system("pause");
                //system("cls");
                displayGame(rows, columns, zombie);
                cout << endl;
                // break;
            }
            else if (choose == 'n' || choose == 'N')
            {
                cout << endl;
                cout << "Game Loading..." << endl;
                cout << endl;
                system("pause");
                system("cls");
                displayGame(rows, columns, zombie);
                cout << endl;
                break;
            }
            else
            {
                cin.clear();
                cin.ignore();
                cout << "Invalid selection, please try again!" << endl;
                cout << endl;
                cin >> choose;
            }
        case 'Q':
            done = true;
            cout << "GOOD BYE!!" << endl;
            cout << endl;
            system("pause");
            break;

        default:
            cout << "Invalid selection, please try again!" << endl;
            cout << endl;
        }
        // system("pause");
        // system("cls");
    } while (!done);
}
