#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int main(){
    bool menu=true;
    while (menu==true){

        system("cls");

        int width = 20;
        int height = 20;


        int snakeX = width / 2;
        int snakeY = height / 2;
        int fruitX = rand() % width;
        int fruitY = rand() % height;
        int score = 0;


        int tailX[400];
        int tailY[400];
        int nTail = 0;


        int arah = 0;

        int menu;
        bool status = false;
        cout<<"============================================="<<endl;
        cout<<"=  ssssss  nnnnnn  aaaaaa  k     k  eeeeee  ="<<endl;
        cout<<"=  s       n    n  a    a  k   k    e       ="<<endl;
        cout<<"=  ssssss  n    n  aaaaaa  k k      eeeeee  ="<<endl;
        cout<<"=       s  n    n  a    a  k   k    e       ="<<endl;
        cout<<"=  ssssss  n    n  a    a  k     k  eeeeee  ="<<endl;
        cout<<"============================================="<<endl;
        cout<<"[1] Play"<<endl;
        cout<<"[2] Exit"<<endl;
        cout<<"Select menu: ";
        cin>>menu;
        if (menu==1){

            system("cls");
            int difficulty;
            cout<<"============================================="<<endl;
            cout<<"=  ssssss  nnnnnn  aaaaaa  k     k  eeeeee  ="<<endl;
            cout<<"=  s       n    n  a    a  k   k    e       ="<<endl;
            cout<<"=  ssssss  n    n  aaaaaa  k k      eeeeee  ="<<endl;
            cout<<"=       s  n    n  a    a  k   k    e       ="<<endl;
            cout<<"=  ssssss  n    n  a    a  k     k  eeeeee  ="<<endl;
            cout<<"============================================="<<endl;
            cout<<"Pilih tingkat kesulitan:"<<endl;
            cout<<"[1] Easy "<<endl;
            cout<<"[2] Normal"<<endl;
            cout<<"[3] Extreme"<<endl;
            cout<<"Masukkan angka: ";
            cin>>difficulty;
            if (difficulty==1){
                while (status==false) {

                system("cls");


                COORD coord;
                coord.X = 0;
                coord.Y = 0;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);


                for (int i = 0; i <= width + 2; i++) {
                    cout << "#";
                }
                cout << endl;

                for (int i = 0; i < height; i++) {
                    for (int j = 0; j < width; j++) {
                        if (j == 0) {
                            cout << "#";
                        }

                        if (i == snakeY && j == snakeX) {
                            cout << "O";
                        }
                        else if (i == fruitY && j == fruitX) {
                            cout << "*";
                        }
                        else {
                            bool printTail = false;
                            for (int k = 0; k < nTail; k++) {
                                if (tailX[k] == j && tailY[k] == i) {
                                    cout << "o";
                                    printTail = true;
                                    break;
                                }
                            }
                            if (!printTail) {
                                cout << " ";
                            }
                        }

                        if (j == width - 1) {
                            cout << "#";
                        }
                    }
                    cout << endl;
                }


                for (int i = 0; i < width + 2; i++) {
                    cout << "#";
                }
                cout << endl;

                cout << "Score: " << score << endl;
                cout << "Tekan 'x' untuk keluar." << endl;


                if (_kbhit()) {
                    char key = _getch();
                    if ((key == 'a' || key == 'A') && arah != 2) {
                        arah = 1;
                    } else if ((key == 'd' || key == 'D') && arah!= 1) {
                        arah = 2;
                    } else if ((key == 'w' || key == 'W') && arah != 4) {
                        arah = 3;
                    } else if ((key == 's' || key == 'S') && arah != 3) {
                        arah = 4;
                    } else if (key == 'x' || key == 'X') {
                        status = true;
                    }
                }



                int prevX = tailX[0];
                int prevY = tailY[0];
                int prev2X, prev2Y;
                tailX[0] = snakeX;
                tailY[0] = snakeY;

                for (int i = 1; i < nTail; i++) {
                    prev2X = tailX[i];
                    prev2Y = tailY[i];
                    tailX[i] = prevX;
                    tailY[i] = prevY;
                    prevX = prev2X;
                    prevY = prev2Y;
                }


                if (arah == 1) {
                    snakeX--;
                } else if (arah == 2) {
                    snakeX++;
                } else if (arah == 3) {
                    snakeY--;
                } else if (arah == 4) {
                    snakeY++;
                }


                if (snakeX < 0 || snakeX >= width || snakeY < 0 || snakeY >= height) {
                    status=true;


                }


                for (int i = 0; i < nTail; i++) {
                    if (tailX[i] == snakeX && tailY[i] == snakeY) {
                        status=true;


                    }
                }


                if (snakeX == fruitX && snakeY == fruitY) {
                    score += 10;
                    nTail++;
                    fruitX = rand() % width;
                    fruitY = rand() % height;
                }

                Sleep(120);
            }




            system("cls");
            cout << "===========================" << endl;
            cout << "        GAME OVER!         " << endl;
            cout << "    Skor Akhir: " << score << endl;
            cout << "===========================" << endl;
            system("pause");
            }



            if (difficulty==2){
                while (status==false) {
                system("cls");


                COORD coord;
                coord.X = 0;
                coord.Y = 0;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

                for (int i = 0; i < width + 2; i++) {
                    cout << "#";
                }
                cout << endl;

                for (int i = 0; i < height; i++) {
                    for (int j = 0; j < width; j++) {
                        if (j == 0) {
                            cout << "#";
                        }

                        if (i == snakeY && j == snakeX) {
                            cout << "O";
                        } else if (i == fruitY && j == fruitX) {
                            cout << "*";
                        } else {
                            bool printTail = false;
                            for (int k = 0; k < nTail; k++) {
                                if (tailX[k] == j && tailY[k] == i) {
                                    cout << "o";
                                    printTail = true;
                                    break;
                                }
                            }
                            if (!printTail) {
                                cout << " ";
                            }
                        }

                        if (j == width - 1) {
                            cout << "#";
                        }
                    }
                    cout << endl;
                }


                for (int i = 0; i < width + 2; i++) {
                    cout << "#";
                }
                cout << endl;

                cout << "Score: " << score << endl;
                cout << "Tekan 'x' untuk keluar." << endl;


                if (_kbhit()) {
                    char key = _getch();
                    if ((key == 'a' || key == 'A') && arah != 2) {
                        arah = 1;
                    } else if ((key == 'd' || key == 'D') && arah != 1) {
                        arah = 2;
                    } else if ((key == 'w' || key == 'W') && arah != 4) {
                        arah = 3;
                    } else if ((key == 's' || key == 'S') && arah != 3) {
                        arah = 4;
                    } else if (key == 'x' || key == 'X') {
                        status = true;
                    }
                }


                int prevX = tailX[0];
                int prevY = tailY[0];
                int prev2X, prev2Y;
                tailX[0] = snakeX;
                tailY[0] = snakeY;

                for (int i = 1; i < nTail; i++) {
                    prev2X = tailX[i];
                    prev2Y = tailY[i];
                    tailX[i] = prevX;
                    tailY[i] = prevY;
                    prevX = prev2X;
                    prevY = prev2Y;
                }

                if (arah == 1) {
                    snakeX--;
                } else if (arah == 2) {
                    snakeX++;
                } else if (arah == 3) {
                    snakeY--;
                } else if (arah == 4) {
                    snakeY++;
                }

                if (snakeX < 0 || snakeX >= width || snakeY < 0 || snakeY >= height) {
                    status=true;


                }

                for (int i = 0; i < nTail; i++) {
                    if (tailX[i] == snakeX && tailY[i] == snakeY) {
                        status=true;


                    }
                }

                if (snakeX == fruitX && snakeY == fruitY) {
                    score += 10;
                    nTail++;
                    fruitX = rand() % width;
                    fruitY = rand() % height;
                }

                Sleep(80);
            }

            }
            else if(difficulty==3){
                while (status==false) {
                system("cls");



                COORD coord;
                coord.X = 0;
                coord.Y = 0;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);


                for (int i = 0; i < width + 2; i++) {
                    cout << "#";
                }
                cout << endl;


                for (int i = 0; i < height; i++) {
                    for (int j = 0; j < width; j++) {
                        if (j == 0) {
                            cout << "#";
                        }

                        if (i == snakeY && j == snakeX) {
                            cout << "O";
                        } else if (i == fruitY && j == fruitX) {
                            cout << "*";
                        } else {
                            bool printTail = false;
                            for (int k = 0; k < nTail; k++) {
                                if (tailX[k] == j && tailY[k] == i) {
                                    cout << "o";
                                    printTail = true;
                                    break;
                                }
                            }
                            if (!printTail) {
                                cout << " ";
                            }
                        }

                        if (j == width - 1) {
                            cout << "#";
                        }
                    }
                    cout << endl;
                }


                for (int i = 0; i < width + 2; i++) {
                    cout << "#";
                }
                cout << endl;

                cout << "Score: " << score << endl;
                cout << "Tekan 'x' untuk keluar." << endl;



                if (_kbhit()) {
                    char key = _getch();
                    if ((key == 'a' || key == 'A') && arah != 2) {
                        arah = 1;
                    } else if ((key == 'd' || key == 'D') && arah != 1) {
                        arah = 2;
                    } else if ((key == 'w' || key == 'W') && arah != 4) {
                        arah = 3;
                    } else if ((key == 's' || key == 'S') && arah != 3) {
                        arah = 4;
                    } else if (key == 'x' || key == 'X') {
                        status = true;
                    }
                }



                int prevX = tailX[0];
                int prevY = tailY[0];
                int prev2X, prev2Y;
                tailX[0] = snakeX;
                tailY[0] = snakeY;

                for (int i = 1; i < nTail; i++) {
                    prev2X = tailX[i];
                    prev2Y = tailY[i];
                    tailX[i] = prevX;
                    tailY[i] = prevY;
                    prevX = prev2X;
                    prevY = prev2Y;
                }


                if (arah == 1) {
                    snakeX--;
                } else if (arah == 2) {
                    snakeX++;
                } else if (arah == 3) {
                    snakeY--;
                } else if (arah == 4) {
                    snakeY++;
                }


                if (snakeX < 0 || snakeX >= width || snakeY < 0 || snakeY >= height) {
                    status=true;


                }


                for (int i = 0; i < nTail; i++) {
                    if (tailX[i] == snakeX && tailY[i] == snakeY) {
                        status=true;


                    }
                }


                if (snakeX == fruitX && snakeY == fruitY) {
                    score += 10;
                    nTail++;
                    fruitX = rand() % width;
                    fruitY = rand() % height;
                }

                Sleep(50);
            }
            }


            else {
                cout<<"Harap masukkan angka yang valid!"<<endl;
                system("pause");
                continue;
            }




            system("cls");
            cout << "===========================" << endl;
            cout << "        GAME OVER!         " << endl;
            cout << "    Skor Akhir: " << score << endl;
            cout << "===========================" << endl;
            system("pause");





        }



        if (menu==2){
            system("cls");
            cout<<"============================================="<<endl;
            cout<<"=  ssssss  nnnnnn  aaaaaa  k     k  eeeeee  ="<<endl;
            cout<<"=  s       n    n  a    a  k   k    e       ="<<endl;
            cout<<"=  ssssss  n    n  aaaaaa  k k      eeeeee  ="<<endl;
            cout<<"=       s  n    n  a    a  k   k    e       ="<<endl;
            cout<<"=  ssssss  n    n  a    a  k     k  eeeeee  ="<<endl;
            cout<<"============================================="<<endl;
            cout<<"Terimakasih telah bermain!";
            break;
        }
    }




    return 0;
}
