#include <iostream>
#include "tubes.h"


int mainmenu(ListBus &B, ListSupir &S, ListRelasi &R){
    bool status = true;
    string nama,platno,kode;
    adrbus Bis,Bus;
    adrsupir Supir,Assis;
    adrrelasi Relasi;
    char jaw,kerjaan,tanda;
    int key;
    do{
        Bus,Bis,Supir,Assis,Relasi = NULL;
        cout<<"\tMenu"<<endl;
        cout<<" 1. Insert Data Bus"<<endl;
        cout<<" 2. Insert Data Supir"<<endl;
        cout<<" 3. Buat Relasi"<<endl;
        cout<<" 4. Hapus Data Bus"<<endl;
        cout<<" 5. Hapus Data Supir"<<endl;
        cout<<" 6. View Bus"<<endl;
        cout<<" 7. View Supir"<<endl;
        cout<<" 8. View History Penggunaan"<<endl;
        cout<<" 9. View Semua Supir Dengan Bis Yg Pernah Dikendarai"<<endl;
        cout<<"10. View Supir Yg Mengendarai Suatu Bis"<<endl;
        cout<<"11. Cek Banyaknya Bus yang Pernah Dikendarai"<<endl;
        cout<<" 0. EXIT"<<endl;
        cin>>key;
        system ("CLS");
        switch (key){
            case 1:
                cout<<"Nama Bus: ";
                cin>>nama;
                cout<<endl;
                cout<<"Plat Nomor: ";
                cin>>platno;
                cout<<endl;
                Bus = AlokasiBus(nama,platno);
                insertBus(B,Bus);
                break;
            case 2:
                cout<<"Nama: ";
                cin>>nama;
                cout<<endl;
                cout<<"Kode: ";
                cin>>kode;
                cout<<endl;
                Supir = AlokasiSupir(nama,kode);
                insertSupir(S,Supir);
                break;
            case 3:
                PrintBus(B);
                Assis = NULL;
                cout<<"Masukkan Nama Bus: ";
                cin>>nama;
                cout<<endl;
                Bis = searchBus(B,nama);
                PrintSupir(S);
                cout<<"Masukkan Nama Supir: ";
                cin>>nama;
                cout<<endl;
                Supir = searchSupir(S,nama);
                cout<<"Butuh Assisten? (Y/T) ";
                cin>>jaw;
                cout<<endl;
                if (jaw=='Y'){
                    cout<<"Masukkan Nama Assisten: ";
                    cin>>nama;
                    cout<<endl;
                    Assis = searchSupir(S,nama);
                }
                if (((jaw=='Y')&&((Bis==NULL)||(Supir==NULL)||(Assis==NULL))) || ((jaw=='N')&&((Bis==NULL)||(Supir==NULL)))){
                    cout<<"Ada Nama Yang Salah, Silahkan Ulangi Lagi"<<endl;
                }else{
                    Relasi = AlokasiRelasi(Bis,Supir,Assis);
                    insertRelasi(R,Relasi);
                    cout<<"Berhasil Membuat Relasi"<<endl;
                }
                break;
            case 4:
                cout<<"List Bus: "<<endl;
                PrintBus(B);
                cout<<endl;
                cout<<"Masukkan Nama Bus: "<<endl;
                cin>>nama;
                cout<<endl;
                Bis = searchBus(B,nama);
                if (Bis==NULL){
                    cout<<"Nama Bus salah, Bus tidak Ditemukan"<<endl;
                }else{
                    deleteBus(B,Bis);
                }
                break;
            case 5:
                cout<<"List Supir: "<<endl;
                PrintSupir(S);
                cout<<endl;
                cout<<"Masukkan Nama: "<<endl;
                cin>>nama;
                cout<<endl;
                Supir = searchSupir(S,nama);
                if (Supir==NULL){
                    cout<<"Nama salah, Supir tidak Ditemukan"<<endl;
                }else{
                    deleteSupir(S,Supir);
                }
                break;
            case 6:
                cout<<"List Bus: "<<endl;
                PrintBus(B);
                break;
            case 7:
                cout<<"List Supir: "<<endl;
                PrintSupir(S);
                break;
            case 8:
                cout<<"History Penggunaan: "<<endl;
                PrintRelasi(R);
                break;
            case 9:
                printSupirdgnBis(S,R);
                break;
            case 10:
                PrintBus(B);
                cout<<"Masukkan Nama Bis: ";
                cin>>nama;
                cout<<endl;
                PrintSupirSiBus(R,nama);
                break;
            case 11:
                cout<<"Supir atau Assisten? (S/A)";
                cin>>kerjaan;
                cout<<endl;
                cout<<"Paling Banyak atau Paling Sedikit? (>/<)";
                cin>>tanda;
                cout<<endl;
                HitungBanyakDikit(R,S,kerjaan,tanda);
                break;
            case 0:
                status = false;
                break;
        }
        
    }while (status);
    return 0;
}

void NgisiRelasi(ListRelasi &R, ListSupir &S, ListBus &B){
    adrrelasi Relasi;
    adrbus Bis;
    adrsupir Supir,Assis;
    Relasi,Bis,Supir = NULL;
    Bis =  searchBus(B,"Tayo");
    Supir = searchSupir(S,"Brian");
    Assis = searchSupir(S,"Letty");
    Relasi = AlokasiRelasi(Bis,Supir,Assis);
    insertRelasi(R,Relasi);
    
    Relasi,Bis,Supir = NULL;
    Bis =  searchBus(B,"Tayo");
    Supir = searchSupir(S,"Dominic");
    Assis = searchSupir(S,"Brian");
    Relasi = AlokasiRelasi(Bis,Supir,Assis);
    insertRelasi(R,Relasi);
    
    Relasi,Bis,Supir = NULL;
    Bis =  searchBus(B,"Thomas");
    Supir = searchSupir(S,"Brian");
    Assis = searchSupir(S,"Letty");
    Relasi = AlokasiRelasi(Bis,Supir,Assis);
    insertRelasi(R,Relasi);
    
    Relasi,Bis,Supir = NULL;
    Bis =  searchBus(B,"Budiman");
    Supir = searchSupir(S,"Brian");
    Assis = searchSupir(S,"Dominic");
    Relasi = AlokasiRelasi(Bis,Supir,Assis);
    insertRelasi(R,Relasi);
    
    Relasi,Bis,Supir = NULL;
    Bis =  searchBus(B,"Thomas");
    Supir = searchSupir(S,"Dominic");
    Assis = searchSupir(S,"Letty");
    Relasi = AlokasiRelasi(Bis,Supir,Assis);
    insertRelasi(R,Relasi);
}

void NgisiListBus(ListBus &B){
    adrbus Bus;
    Bus = AlokasiBus("Tayo","B123EHE");
    insertBus(B,Bus);
    
    Bus = AlokasiBus("Thomas","D3KAT");
    insertBus(B,Bus);
    
    Bus = AlokasiBus("Budiman","M412VEL");
    insertBus(B,Bus);
}

void NgisiListSupir(ListSupir &S){
    adrsupir Supir;
    Supir = AlokasiSupir("Brian","BRO");
    insertSupir(S,Supir);
    
    Supir = AlokasiSupir("Dominic","DOM");
    insertSupir(S,Supir);
    
    Supir = AlokasiSupir("Letty","LTY");
    insertSupir(S,Supir);
}

int main()
{
    ListBus B;
    ListSupir S;
    ListRelasi R;
    createListBus(B);
    createListSupir(S);
    createListRelasi(R);
    int angka;
    do{
        cin>>angka;
        if (angka == 1){
            NgisiListBus(B);
        }
        if (angka == 2){
            NgisiListSupir(S);
        }
        if (angka == 3){
            NgisiRelasi(R,S,B);
        }
    }while (angka != 0);
    mainmenu(B,S,R);
    return 0;
}
