#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct Information
{
    string  strName; // Ten quoc gia
    int     nPopulation; // Dan so
    int     nLandArea; // Dien tich dat
};

struct Node
{
    Information info;
    Node        *nextName;
    Node        *nextPopulation;
    Node        *nextLandArea;
};

Node    *pHead;

void Insert(Node *&pHead, string strName, int nPopulation, int nLandArea)
{
    //std::cout << "\nLan: " << ++iCount;
    Node    *pNew = new Node();

    pNew->info.strName = strName;
    pNew->info.nPopulation = nPopulation;
    pNew->info.nLandArea = nLandArea;
    pNew->nextName = NULL;
    pNew->nextPopulation = NULL;
    pNew->nextLandArea = NULL;

    if(pHead->nextName == NULL)
    {
        pHead->nextName = pNew;
        pHead->nextPopulation = pNew;
        pHead->nextLandArea = pNew;
        return;
    }
    /////////////////////////////////////////////
    //Create Country Name List
    Node    *pTemp0 = NULL;
    Node    *pTemp = pHead->nextName;
    while(pTemp != NULL && strName.compare(pTemp->info.strName) > 0)
    {
        //++iCountName;        
        //Sleep(300);
        //std::cout << "\nSo lan ten: " << iCountName << "\tTen: " << pTemp->info.strName;
        pTemp0 = pTemp;
        pTemp = pTemp->nextName;
    }
    if(pTemp == pHead->nextName)
    {
        pNew->nextName = pHead->nextName;
        pHead->nextName = pNew;
    }
    else
    {
        pNew->nextName = pTemp;
        pTemp0->nextName = pNew;
    }

    /////////////////////////////////////////////
    //Create Population List
    pTemp0 = NULL;
    pTemp = pHead->nextPopulation;
    while(pTemp != NULL && nPopulation > pTemp->info.nPopulation)
    {
        pTemp0 = pTemp;
        pTemp = pTemp->nextPopulation;
    }
    if(pTemp == pHead->nextPopulation)
    {
        pNew->nextPopulation = pHead->nextPopulation;
        pHead->nextPopulation = pNew;
    }
    else
    {
        pNew->nextPopulation = pTemp;
        pTemp0->nextPopulation = pNew;
    }

    /////////////////////////////////////////////
    //Create Land Area List
    pTemp0 = NULL;
    pTemp = pHead->nextLandArea;
    while(pTemp != NULL && nLandArea > pTemp->info.nLandArea)
    {
        pTemp0 = pTemp;
        pTemp = pTemp->nextLandArea;
    }
    if(pTemp == pHead->nextLandArea)
    {
        pNew->nextLandArea = pHead->nextLandArea;
        pHead->nextLandArea = pNew;
    }
    else
    {
        pNew->nextLandArea = pTemp;
        pTemp0->nextLandArea = pNew;
    }
}

void createList()
{
    ifstream csvFile;
    string strPathCSVFile = "CountriesList.csv";
    csvFile.open(strPathCSVFile.c_str());

    if (!csvFile.is_open())
    {
        cout << "Path Wrong!!!!" << endl;
        return;
    }

    string line;
    getline(csvFile, line); // skip the 1st line

    while (getline(csvFile,line))
    {
        if (line.empty()) // skip empty lines:
        {
            continue;
        }
        std::istringstream s(line);
        std::string field;
        string  strName;
        int     nPopulation;
        int     nLandArea;
        for(int i = 0; i < 3; i++)
        {
            getline(s, field, ',');
            if(i == 0)
            {
                strName = field;
            }
            if (i == 1)
            {
                nPopulation = atoi(field.c_str());
            }
            if (i == 2)
            {
                nLandArea = atoi(field.c_str());
            }
        }
        Insert(pHead, strName, nPopulation, nLandArea);
    }
}

int countriesNum(Node *pHead)
{
    if (!pHead)
    {
        return 0;
    }
    
    int iCount = 0;
    if (pHead->nextName)
    {
        Node* pTemp = pHead->nextName;
        while (pTemp)
        {
            ++iCount;
            pTemp = pTemp->nextName;
        }
    }
    
    return iCount;
}

void listbyNameAsc(Node *pHead)
{
    if (!pHead)
    {
        return;
    }
    int iCount = 0;
    if (pHead->nextName)
    {
        Node* i = pHead;
        Node* j = NULL;
        while (i->nextName->nextName)
        {
            j = i->nextName;
            string str1 = i->nextName->info.strName;
            string str2 = "";
            while (j->nextName)
            {
                str2 = j->nextName->info.strName;
                str1.compare(str2);
                if (str1.compare(str2) <= 1)
                {
                    swap(i->nextName->info, j->nextName->info);
                }
                
                j = j->nextName;
            }
            
            i = i->nextName;
        }

        i = pHead;
        while (i->nextName)
        {
            cout << "\n" << setw(25)<< left << i->nextName->info.strName;
            cout << setw(12) << right << i->nextName->info.nPopulation;
            cout << setw(12) << right << i->nextName->info.nLandArea;
            i = i->nextName;
        }
        cout << "\n\n";
    }
}

void listbyNameDes(Node *pHead)
{
    if (!pHead)
    {
        return;
    }
    int iCount = 0;
    if (pHead->nextName)
    {
        Node* i = pHead;
        Node* j = NULL;
        while (i->nextName->nextName)
        {
            j = i->nextName;
            string str1 = i->nextName->info.strName;
            string str2 = "";
            while (j->nextName)
            {
                str2 = j->nextName->info.strName;
                str1.compare(str2);
                if (str1.compare(str2) <= 1)
                {
                    swap(i->nextName->info, j->nextName->info);
                }
                
                j = j->nextName;
            }
            
            i = i->nextName;
        }

        i = pHead;
        while (i->nextName)
        {
            cout << "\n" << setw(25)<< left << i->nextName->info.strName;
            cout << setw(12) << right << i->nextName->info.nPopulation;
            cout << setw(12) << right << i->nextName->info.nLandArea;
            i = i->nextName;
        }
        cout << "\n\n";
    }
}

void listbyPopulationAsc(Node *pHead)
{

}

void listbyPopulationDes(Node *pHead)
{

}

void listbyAreaAsc(Node *pHead)
{

}

void listbyAreaDes(Node *pHead)
{

}

Node* searchbyName(Node *pHead)
{

    return NULL;
}

void searchbyPopulation(Node *pHead)
{

}

void searchbyArea(Node *pHead)
{

}

void insertCountry(Node *&pHead)
{
    string strName;
    int nPopulation;
    int nLandArea;
    cout << "Nhap ten quoc gia: ";
    cin.ignore(256, '\n');
    getline(cin, strName);
    cout << "Nhap dan so: ";
    cin >> nPopulation;
    cout << "Nhap dien tich dat: ";
    cin >> nLandArea;

    cout << "\n\nTen: " << strName << "\n";
    cout << "DS: " << nPopulation << "\n";
    cout << "DT: " << nLandArea << "\n";

    // ofstream csvFileOut;
    // string strPathCSVFile = "CountriesList1.csv";
    // csvFileOut.open(strPathCSVFile, ios::out);
    // csvFileOut << strName + ",";
    // csvFileOut << nPopulation + ",";
    // csvFileOut << nLandArea + ",";
    // csvFileOut.close();

    // Insert(pHead, strName, nPopulation, nLandArea);
}

void deleteCountry(Node *&pHead)
{

}

int main()
{
    pHead = new Node();

    pHead->nextName = NULL;
    pHead->nextPopulation = NULL;
    pHead->nextLandArea = NULL;
    createList();

    int     nChoice = -1;

    do
    {
        ///////////////////////////////////////
        cout << "   CHON CHUC NANG" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "1. So luong quoc gia" << endl;
        cout << "2. Danh sach xep theo ten (A->Z)" << endl;
        cout << "3. Danh sach xep theo ten (Z->A)" << endl;
        cout << "4. Danh sach xep theo dan so (it->nhieu)" << endl;
        cout << "5. Danh sach xep theo dan so (nhieu->it)" << endl;
        cout << "6. Danh sach xep theo dien tich (nho->lon)" << endl;
        cout << "7. Danh sach xep theo dien tich (lon->nho)" << endl;
        cout << "8. Tim kiem theo ten" << endl;
        cout << "9. Tim kiem theo dan so" << endl;
        cout << "10.Tim kiem theo dien tich" << endl;
        cout << "11.Them quoc gia" << endl;
        cout << "12.Xoa quoc gia" << endl;

        cout << "Nhap lua chon: ";
        cin >> nChoice;

        Node* pTemp;
        switch(nChoice)
        {
        case 1:
            cout << "So luong quoc gia: " << countriesNum(pHead) << endl;
            break;
        case 2:
            listbyNameAsc(pHead);
            break;
        case 3:
            listbyNameDes(pHead);
            break;
        case 4:
            listbyPopulationAsc(pHead);
            break;
        case 5:
            listbyPopulationDes(pHead);
            break;
        case 6:
            listbyAreaAsc(pHead);
            break;
        case 7:
            listbyAreaDes(pHead);
            break;
        case 8:
            pTemp = searchbyName(pHead);
            if(pTemp!=NULL)
            {
                cout << "Thong tin quoc gia: " << endl;
                cout << setw(25) << left << pTemp->info.strName;
                cout << setw(12) << right << pTemp->info.nPopulation;
                cout << setw(12) << right << pTemp->info.nLandArea;
                cout << endl;
            }
            else
                cout << "Khong ton tai quoc gia nay trong danh sach" << endl;
            break;
        case 9:
            searchbyPopulation(pHead);
            break;
        case 10:
            searchbyArea(pHead);
            break;
        case 11:
            insertCountry(pHead);
            break;
        case 12:
            deleteCountry(pHead);
            break;
        }
    } while(nChoice != 0);

    return 0;
}
