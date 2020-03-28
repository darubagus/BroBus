#include <iostream>
#include <stdlib.h>
#define nil NULL
#define namaB(B) B->namabus
#define platB(B) B->platno
#define prevB(B) B -> prevbus
#define nextB(B) B -> nextbus
#define firstB(B) B.FirstBus
#define lastB(B) B.LastBus

#define namaS(S) S->namasupir
#define kodeS(S) S->kode
#define nextS(S) S->nextsupir
#define prevS(S) S->prevsupir
#define firstS(S) S.FirstSupir
#define lastS(S) S.LastSupir

#define nextR(R) R->next
#define prevR(R) R->prev
#define Rbus(R) R->Pbus
#define Rsupir(R) R->Psupir
#define Rasist(R) R->Pasisten
#define firstR(R) R.First
#define lastR(R) R.Last


using namespace std;

typedef struct IsiListBus *adrbus;
typedef struct IsiListSupir *adrsupir;
typedef struct IsiListRelasi *adrrelasi;

struct IsiListBus{
    string namabus;
    string platno;
    adrbus nextbus;
    adrbus prevbus;
};
struct ListBus{
    adrbus FirstBus;
    adrbus LastBus;
};

struct IsiListSupir{
    string namasupir;
    string kode;
    adrsupir nextsupir;
    adrsupir prevsupir;
};

struct ListSupir{
    adrsupir FirstSupir;
    adrsupir LastSupir;
};

struct IsiListRelasi{
    adrrelasi next;
    adrrelasi prev;
    adrbus Pbus;
    adrsupir Psupir;
    adrsupir Pasisten;
};

struct ListRelasi{
    adrrelasi First;
    adrrelasi Last;
};

void createListBus(ListBus &Bus);
void createListSupir(ListSupir &Supir);
void createListRelasi(ListRelasi &R);
adrbus AlokasiBus(string nama, string platno);
adrsupir AlokasiSupir(string nama, string kode);
adrrelasi AlokasiRelasi(adrbus Bus, adrsupir Supir, adrsupir Asisten);
void insertBus(ListBus &B, adrbus Bus);
void insertSupir(ListSupir &S, adrsupir Supir);
void insertRelasi(ListRelasi &R, adrrelasi Relasi);
void deleteBus(ListBus &B, adrbus Bus);
void deleteSupir(ListSupir &S, adrsupir Supir);
adrbus searchBus(ListBus B, string nama);
adrsupir searchSupir(ListSupir S, string nama);
void PrintBus(ListBus B);
void PrintSupir(ListSupir S);
void PrintRelasi(ListRelasi R);
void printSupirdgnBis(ListSupir S,ListRelasi R);
void PrintSupirSiBus(ListRelasi R, string nama);
void HitungBanyakDikit(ListRelasi R, ListSupir S, char kerjaan, char tanda);

