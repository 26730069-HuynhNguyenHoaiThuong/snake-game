#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>
using namespace std;

void gotoxy( int column, int line );

// ============================================================================
// SV3: Pham Phu Nguyen Hung - MSSV: 26730023 - Nhanh: An-Moi
// Nhiem vu: Dinh nghia moi (Point Qua), sinh moi ngau nhien & xu ly ran an moi tang do dai
// ============================================================================

struct Point{
    int x, y;
};

class CONRAN{
public:
    struct Point A[100];
    int DoDai;
    CONRAN(){
        DoDai = 3;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    }

    // Kiem tra vi tri co trung voi than ran khong
    bool TrungThan(Point p){
        for (int i = 0; i < DoDai; i++){
            if (A[i].x == p.x && A[i].y == p.y)
                return true;
        }
        return false;
    }

    // Sinh moi ngau nhien tranh trung than ran
    void SinhMoi(Point &Qua){
        do {
            Qua.x = rand() % 30 + 5;
            Qua.y = rand() % 15 + 3;
        } while (TrungThan(Qua));
    }

    // Ve than ran va moi (Qua)
    void Ve(Point Qua){
        for (int i = 0; i < DoDai; i++){
            gotoxy(A[i].x, A[i].y);
            cout << "X";
        }
        // Ve moi
        gotoxy(Qua.x, Qua.y);
        cout << "*";
    }

    // Di chuyen va kiem tra an moi
    void DiChuyen(int Huong, Point &Qua){
        for (int i = DoDai - 1; i > 0; i--)
            A[i] = A[i - 1];
        if (Huong == 0) A[0].x = A[0].x + 1;
        if (Huong == 1) A[0].y = A[0].y + 1;
        if (Huong == 2) A[0].x = A[0].x - 1;
        if (Huong == 3) A[0].y = A[0].y - 1;

        // Logic khi ran an moi: tang do dai va sinh moi moi
        if (A[0].x == Qua.x && A[0].y == Qua.y){
            if (DoDai < 100){
                DoDai++;
            }
            SinhMoi(Qua);
        }
    }
};

int main()
{
    srand((unsigned int)time(NULL));
    CONRAN r;
    int Huong = 0;
    char t;

    // Khoi tao moi ban dau
    Point Qua;
    r.SinhMoi(Qua);

    while (1){
        if (kbhit()){
            t = getch();
            if (t == 'a') Huong = 2;
            if (t == 'w') Huong = 3;
            if (t == 'd') Huong = 0;
            if (t == 'x') Huong = 1;
        }
        system("cls");
        gotoxy(2, 1);
        cout << "Diem so: " << (r.DoDai - 3) * 10;
        r.Ve(Qua);
        r.DiChuyen(Huong, Qua);
        Sleep(200);
    }

    return 0;
}

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle( STD_OUTPUT_HANDLE ),
        coord
    );
}
