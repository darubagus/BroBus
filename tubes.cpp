#include "tubes.h"

void createListBus(ListBus &Bus){
    firstB(Bus) = NULL;
    lastB(Bus) = NULL;
}

void createListSupir(ListSupir &Supir){
    firstS(Supir) = NULL;
    lastS(Supir) = NULL;
}

void createListRelasi(ListRelasi &R){
    firstR(R) = NULL;
    lastR(R) = NULL;
}

adrbus AlokasiBus(string nama, string platno){
    adrbus B = new IsiListBus;
    namaB(B) = nama;
    platB(B) = platno;
    nextB(B) = NULL;
    prevB(B) = NULL;
    return B;
}

adrsupir AlokasiSupir(string nama, string kode){
    adrsupir S = new IsiListSupir;
    namaS(S) = nama;
    kodeS(S) = kode;
    nextS(S) = NULL;
    prevS(S) = NULL;
    return S;
}

adrrelasi AlokasiRelasi(adrbus Bus, adrsupir Supir, adrsupir Asisten){
    adrrelasi R = new IsiListRelasi;
    Rbus(R) = Bus;
    Rsupir(R) = Supir;
    Rasist(R) = Asisten;
    nextR(R) = NULL;
    prevR(R) = NULL;
    return (R);
}

void insertBus(ListBus &B, adrbus Bus){
    if ((firstB(B)==NULL)&&(lastB(B)==NULL)){
        firstB(B) = Bus;
        lastB(B) = Bus;
    }else{
        adrbus cek;
        cek = searchBus(B,namaB(Bus));
        if (cek==NULL){
            bool sama = false;
            adrbus P = firstB(B);
            while (P != NULL){
                if ((namaB(P)==namaB(Bus))&&(platB(P)==platB(Bus))){
                    sama = true;
                }
                P = nextB(P);
            }
            //diatas kalo pake kondisi bus yg di input gaboleh sama persis
            if (!sama){
                nextB(lastB(B)) = Bus;
                prevB(Bus) = lastB(B);
                lastB(B) = Bus;
            }
        }
    }
}

void insertSupir(ListSupir &S, adrsupir Supir){
    if ((firstS(S)==NULL)&&(lastS(S)==NULL)){
        firstS(S) = Supir;
        lastS(S) = Supir;
    }else{
        adrsupir cek;
        cek = searchSupir(S,namaS(Supir));
        if (cek==NULL){
            bool sama = false;
            adrsupir P = firstS(S);
            while (P != NULL){
                if ((namaS(P)==namaS(Supir))&&(kodeS(P)==kodeS(Supir))){
                    sama = true;
                }
                P = nextS(P);
            }
            if (!sama){
                nextS(lastS(S)) = Supir;
                prevS(Supir) = lastS(S);
                lastS(S) = Supir;
            }
        }
    }
}

void insertRelasi(ListRelasi &R, adrrelasi Relasi){
    if ((firstR(R)==NULL)&&(lastR(R)==NULL)){
        firstR(R) = Relasi;
        lastR(R) = Relasi;
    }else{
        nextR(lastR(R)) = Relasi;
        prevR(Relasi) = lastR(R);
        lastR(R) = Relasi;
    }
}

//delete dibawah ini pemanggilannya setelah di search bus nya, jadi udh dapet address bus nya
void deleteBus(ListBus &B, adrbus Bus){
    if ((firstB(B)==Bus)&&(lastB(B)==Bus)){
        firstB(B) = NULL;
        lastB(B) = NULL;
    }else{
        if (firstB(B)==Bus){
            firstB(B) = nextB(Bus);
            prevB(firstB(B)) = NULL;
            nextB(Bus) = NULL;
        }else if (lastB(B)==Bus){
            lastB(B) = prevB(Bus);
            prevB(Bus) = NULL;
            nextB(lastB(B))=NULL;
        }else{
            nextB(prevB(Bus)) = nextB(Bus);
            prevB(nextB(Bus)) = prevB(Bus);
            nextB(Bus) = NULL;
            prevB(Bus) = NULL;
        }
    }
}

//delete dibawah ini pemanggilannya setelah di search supir nya, jadi udh dapet address supir nya
void deleteSupir(ListSupir &S, adrsupir Supir){
    if ((firstS(S)==Supir)&&(lastS(S)==Supir)){
        firstS(S) = NULL;
        lastS(S) = NULL;
    }else{
        if (firstS(S)==Supir){
            firstS(S) = nextS(Supir);
            prevS(firstS(S)) = NULL;
            nextS(Supir) = NULL;
        }else if (lastS(S)==Supir){
            lastS(S) = prevS(Supir);
            prevS(Supir) = NULL;
            nextS(lastS(S))=NULL;
        }else{
            nextS(prevS(Supir)) = nextS(Supir);
            prevS(nextS(Supir)) = prevS(Supir);
            nextS(Supir) = NULL;
            prevS(Supir) = NULL;
        }
    }
}

adrbus searchBus(ListBus B, string nama){
    adrbus P,hasil;
    P = firstB(B);
    hasil = NULL;
    while (P != NULL){
        if (namaB(P)==nama){
            hasil = P;
        }
        P = nextB(P);
    }
    return hasil;
}

adrsupir searchSupir(ListSupir S, string nama){
    adrsupir P,hasil;
    P = firstS(S);
    hasil = NULL;
    while (P != NULL){
        if (namaS(P)==nama){
            hasil = P;
        }
        P = nextS(P);
    }
    return hasil;
}

void PrintBus(ListBus B){
    if((firstB(B)==NULL)&&(lastB(B)==NULL)){
        cout<<"List Kosong"<<endl;
    }else{
        adrbus P;
        P = firstB(B);
        while (P!=NULL){
            cout<<"Nama Bus: "<<namaB(P)<<endl;
            cout<<"Plat Nomor: "<<platB(P)<<endl;
            P = nextB(P);
            cout<<endl;
        }
    }
}

void PrintSupir(ListSupir S){
    if((firstS(S)==NULL)&&(lastS(S)==NULL)){
        cout<<"List Kosong"<<endl;
    }else{
        adrsupir P;
        P = firstS(S);
        while (P!=NULL){
            cout<<"Nama: "<<namaS(P)<<endl;
            cout<<"Kode: "<<kodeS(P)<<endl;
            P = nextS(P);
            cout<<endl;
        }
    }
}

void PrintRelasi(ListRelasi R){
    if((firstR(R)==NULL)&&(lastR(R)==NULL)){
        cout<<"Belum Ada Penggunaan"<<endl;
    }else{
        adrrelasi P;
        int i = 1;
        P = firstR(R);
        while (P!=NULL){
            cout<<"Data "<<i<<endl;
            cout<<"Nama Bus: "<<namaB(Rbus(P))<<endl;
            cout<<"Plat Nomor: "<<platB(Rbus(P))<<endl;
            cout<<"Supir: "<<endl;
            cout<<"Nama: "<<namaS(Rsupir(P))<<endl;
            cout<<"Kode: "<<kodeS(Rsupir(P))<<endl;
            if (Rasist(P)!= NULL){
                cout<<"Asisten: "<<endl;
                cout<<"Nama: "<<namaS(Rasist(P))<<endl;
                cout<<"Kode: "<<kodeS(Rasist(P))<<endl;
            }
            P = nextR(P);
            i++;
            cout<<"============================================"<<endl;
        }
    }
}

void printSupirdgnBis(ListSupir S,ListRelasi R){
    if((firstS(S)==NULL)&&(lastS(S)==NULL)){
        cout<<"List Kosong"<<endl;
    }else{
        adrsupir P;
        P = firstS(S);
        while (P!=NULL){
            adrrelasi Q;
            Q = firstR(R);
            cout<<"*Nama: "<<namaS(P)<<endl;
            cout<<" Kode: "<<kodeS(P)<<endl;
            while (Q!=NULL){
                if (namaS(Rsupir(Q))==namaS(P)){
                    cout<<"Nama Bus: "<<namaB(Rbus(Q))<<endl;
                    cout<<"Plat Nomor: "<<platB(Rbus(Q))<<endl;
                    cout<<endl;
                }
                Q = nextR(Q);
            }
            cout<<"================================="<<endl;
            P = nextS(P);
        }
    }
}

void PrintSupirSiBus(ListRelasi R, string nama){
    if((firstR(R)==NULL)&&(lastR(R)==NULL)){
        cout<<"Belum Ada Penggunaan"<<endl;
    }else{
        adrrelasi P;
        P = firstR(R);
        while (P!=NULL){
            if (namaB(Rbus(P))==nama){
                cout<<"Nama: "<<namaS(Rsupir(P))<<endl;
                cout<<"Kode: "<<kodeS(Rsupir(P))<<endl;
                cout<<endl;
            }
            P = nextR(P);
        }
    }
}

void HitungBanyakDikit(ListRelasi R, ListSupir S, char kerjaan, char tanda){
    adrsupir P,temp;
    adrrelasi Q;
    int tempA,tempB;
    tempA = 0;
    P = firstS(S);
    while (P != NULL){
        tempB = 0;
        Q = firstR(R);
        while (Q!= NULL){
            if (kerjaan =='S'){
                if (namaS(Rsupir(Q))==namaS(P)){
                    tempB++;
                }
            }else if (kerjaan =='A'){
                if (namaS(Rasist(Q))==namaS(P)){
                    tempB++;
                }
            }
            Q = nextR(Q);
        }
        if (tempA == 0){
            tempA = tempB;
            temp = P;
        }else{
            if (tanda == '>'){
                if (tempA < tempB){
                    tempA = tempB;
                    temp = P;
                }
            }else if (tanda == '<'){
                if (tempA > tempB){
                    tempA = tempB;
                    temp = P;
                }
            }
        }
        P = nextS(P);
    }
    cout<<"Nama: "<<namaS(temp)<<endl;
    cout<<"Kode: "<<kodeS(temp)<<endl;
    Q = firstR(R);
    while (Q!= NULL){
        if (kerjaan =='S'){
            if (namaS(Rsupir(Q))==namaS(temp)){
                cout<<"Nama Bus: "<<namaB(Rbus(Q))<<endl;
                cout<<"Plat Nomor: "<<platB(Rbus(Q))<<endl;
                cout<<endl;
            }
        }else if (kerjaan =='A'){
            if (namaS(Rasist(Q))==namaS(temp)){
                cout<<"Nama Bus: "<<namaB(Rbus(Q))<<endl;
                cout<<"Plat Nomor: "<<platB(Rbus(Q))<<endl;
                cout<<endl;
            }
        }
        Q = nextR(Q);
    }
    
}
