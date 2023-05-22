#include <stdio.h>
#include <stdbool.h>

// Membuat Struct Untuk Grid
struct Grid
{
    int x;
    int y;
};

// Membuat Struct Untuk Grid
struct BidakObject
{
    char Name[10];
    int x;
    int y;
    struct Grid TargetPos[];
};

// Membuat Instance dari struct yang sudah dibikin
struct BidakObject BidakVariant[] = {{"Kuda", 2, 2, {}}};

// Fungsi Untuk mencari grid mana saja yang harus dituju
bool CheckGridAround(struct Grid *GridPos)
{
    // Membuat variabel pointer untuk mentarget address dari Bidak Variant array
    struct BidakObject *BidakVariantPtr = &BidakVariant[0];

    // Membuat variabel pointer untuk mentarget address dari Bidak Variant array
    for (int i = 0; i < 8; i++)
    {
        // Jika grid yang di passing di argument sama dengan target position X dan Y. Maka return true jika tidak false.
        if (BidakVariantPtr->TargetPos[i].x == GridPos->x && BidakVariantPtr->TargetPos[i].y == GridPos->y)
        {
            return true;
            break;
        }
    }
    return false;
}

void ShowVisualGrid(int width, int height)
{
    // Membuat variabel pointer untuk struct grid
    struct Grid *NewGridPositionPtr, NewGridPosition;
    NewGridPositionPtr = &NewGridPosition;

    // Melakukan perulangan menurut width dan height untuk membuat grid
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            // lakukan inisialisasi nilai ke grid X dan Y menggunakan pointer
            NewGridPositionPtr->x = x;
            NewGridPositionPtr->y = y;

            // Print penanda grid menurut keadaan yang ada. jika sama dengan posis kuda sekarang maka akan print "K"
            if (BidakVariant->x == NewGridPositionPtr->x && BidakVariant->y == NewGridPositionPtr->y)
                printf("K ");
            // jika sama dengan posis target dari kuda yang telah di cek di fungsi CheckGridAround() maka print "1"
            else if (CheckGridAround(NewGridPositionPtr))
                printf("1 ");
            // Jika tidak keduanya print "0"
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void CalculateBidakTargetPos()
{
    // Mencari offset dari setiap arah yang ada
    int UpTargetOffset = BidakVariant->x - 2;
    int DownTargetOffset = BidakVariant->x + 2;
    int RightTargetOffset = BidakVariant->y + 2;
    int LeftTargetOffset = BidakVariant->y - 2;

    struct Grid NewGrid;
    // lakukan perulangan dan tambahkan posisi target grid yang bisa dituju oleh kuda ke struct
    for (int i = 0; i < 8; i++)
    {
        if (i == 0)
            NewGrid = (struct Grid){UpTargetOffset, BidakVariant->y - 1};
        if (i == 1)
            NewGrid = (struct Grid){UpTargetOffset, BidakVariant->y + 1};
        if (i == 2)
            NewGrid = (struct Grid){BidakVariant->x - 1, LeftTargetOffset};
        if (i == 3)
            NewGrid = (struct Grid){BidakVariant->x + 1, LeftTargetOffset};
        if (i == 4)
            NewGrid = (struct Grid){DownTargetOffset, BidakVariant->y - 1};
        if (i == 5)
            NewGrid = (struct Grid){DownTargetOffset, BidakVariant->y + 1};
        if (i == 6)
            NewGrid = (struct Grid){BidakVariant->x - 1, RightTargetOffset};
        if (i == 7)
            NewGrid = (struct Grid){BidakVariant->x + 1, RightTargetOffset};

        BidakVariant->TargetPos[i] = NewGrid;
    }
}

void koboImaginaryChess(int i, int j, int size, int *chessBoard)
{
    BidakVariant[0].x = i;
    BidakVariant[0].y = j;

    CalculateBidakTargetPos();
    ShowVisualGrid(size, size);
}

int main()
{
    int chessBoard[8][8];

    int i, j, size = 8;

    printf("Masukan Posisi Kuda: ");
    scanf("%d %d", &i, &j);

    koboImaginaryChess(i, j, size, *chessBoard);

    return 0;
}
