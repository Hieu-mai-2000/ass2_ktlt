#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif
//ra khoi lau dai
enum su_kien{
 gau_MadBear=1,
 Amazon_MoonBringer=2,
 yeu_tinh_Elf=3,
 chien_binh_Saxon=4,
 quy_khong_lo_Troll=5,
 Tornbery=6,
 Queen_of_Cards=7,
 Nina_de_Rings =8,
 vuong_sau_rieng =9,
 nhat_antidote=10,
 gap_Odin=11,
 gap_phu_thuy_Merlin=12,
 quai_vat_Omega_Weapon=13,
 than_chet_Hades=14,
 nhat_Scarlet_Hakama=15,
 cong_LockedDoor=16,
 chiec_kien_Paladin=95,
 ngon_giao_Lancelot=96,
 soi_toc_Guinevere=97,
 guom_Excalibur=98,
 gap_Ultimecia=99

};
enum nhan_vat{
  hiep_si_binh_thuong=999,
  hiep_si_Arthur=1000,
  hiep_si_Lancelot=1001,
  cong_chua_Guinevere=1002,
  hiep_si_Paladin =1003,
  hiep_si_rong=1004
};

enum tong_hop{
  trung_doc=1005,
  giai_doc=1006,
  thang =1007,
  thua= 1008,
  con_song=1009,
  da_chet=1010
};

int so_nguyen_to(int number){
    if(number<3) return 0;
    int khong_phai_so_ngto=0;
    for(int i=2;i<number;i++)
     if(number%i==0) {khong_phai_so_ngto=1;break;}
    if(khong_phai_so_ngto==0) return 1;
    return 0;
}

int tam_giac_vuong(int number){
      if(number==888) return 0;
      int arr[16][3]={
   {3, 4, 5},{5, 12, 13},{7, 24, 25},{8, 15, 17},
{9, 40, 41},{11, 60, 61},{12, 35, 37},{13, 84, 85},
{16, 63, 65},{20, 21, 29},{28, 45, 53},{33, 56, 65},
{36, 77, 85},{39, 80, 89},{48, 55, 73},{65, 72, 97}
  };
  
  for(int i=0;i<16;i++)
    {
		 for(int h=1;h<100;h++)
		  {
		  int tam=h*(arr[i][0]+arr[i][1]+arr[i][2]);
		  if(number<tam) break;
		  if(number==tam) return 1;
		  } 
	}
	return 0;
}

int friendly_number(int HP,int gil){
  int total_uoc_of_HP=0;
  int total_uoc_of_gil=0;
  int max=(HP>gil)?HP:gil;
  
  for(int i=1;i<=max;i++)
    {
      if( HP%i == 0 ) total_uoc_of_HP +=i;
      if( gil%i == 0 ) total_uoc_of_gil +=i;
    }
  return ((float)total_uoc_of_HP/HP == (float)total_uoc_of_gil/gil)?1:0;
}

void increa_level(int &level,int &maxHP){
  if(level<10)
  {
    level++;
     maxHP = (maxHP+100 <999)?maxHP+100:999;
  }
}

void kiem_tra_hiep_si(int HP,int &hiepsi){
  if(HP == 999) hiepsi = hiep_si_Arthur;
  else if(HP == 888) hiepsi = hiep_si_Lancelot;
  else if(HP == 777) hiepsi = cong_chua_Guinevere;
  else if(so_nguyen_to(HP)) hiepsi = hiep_si_Paladin;
  else if(tam_giac_vuong(HP)) hiepsi = hiep_si_rong;
  else hiepsi = hiep_si_binh_thuong;
}

int chien_dau(int level,int sukien){
  int b=sukien%10;
  int level_dich=sukien>6?(b>5?b:5):b;
  if(level>=level_dich) return 1;// vi tuong thang tran
  if(level<level_dich) return 0;//vi tuong thua tran
  return 0;
}

int hinh_phat(int &HP,int sukien,int baseDamage){
  int b=sukien%10;
  int level_dich=sukien>6?(b>5?b:5):b;
  HP -= baseDamage*level_dich*10;
  if(HP<=0) return 0;  //thua roi ket thuc chuong trinh
  return 1;
}

void gap_Nina(int &gil,int &tinh_trang,int &HP,int maxHP,int expecial){
  if(expecial){
    if(tinh_trang == trung_doc ) tinh_trang = giai_doc;
    HP = maxHP;//cai nay la doan..nen len eler xem phai khong
  }
  else if(gil>=50) {
    if(tinh_trang == trung_doc){
      tinh_trang = giai_doc;
      gil -=50;
    }
    if(gil) if(HP+gil > maxHP) 
              {
                gil=HP + gil - maxHP;
                HP=maxHP;
              }
              else {
                HP +=gil;
                gil=0;
              }

  }
}

void hinh_phat_Tornbery(int &tinh_trang,int &antidote,int truong_hop,int &number_thu_thach){
  //truong_hop =1 kiem tra co da la dung..va tang bien su kien thu thach
  //truong_hop =2 kiem tra co phai dang dat biet khong
  //truong_hop =3 bi_phat
  if(truong_hop ==1)
  {
    if(number_thu_thach ==5 && tinh_trang == trung_doc) tinh_trang = giai_doc;
    if(antidote!=0 && tinh_trang == trung_doc) 
     {
       antidote--;
       tinh_trang = giai_doc;
     }
    if(0<=number_thu_thach && number_thu_thach <=5) number_thu_thach = number_thu_thach+1;
  }

  if(truong_hop ==3) if(antidote == 0 ) {if(tinh_trang == giai_doc) tinh_trang = trung_doc;}
                     else {antidote--;number_thu_thach=-1;}
  if(number_thu_thach==6) number_thu_thach=-1;
}

void vuon_sau_rieng(int &tinh_trang,int &HP,int maxHP,int &rose,int SH){
  if(tinh_trang == trung_doc) tinh_trang =giai_doc;
  HP = maxHP;
  if(SH) rose=99;
  else rose +=5;
}
//Odin giup do se thang tu 1-7 chua duoc ghi nhan
void Odin(int tinh_trang ,int &number_Odin_giup_do){
   if(tinh_trang != da_chet){
     if(0<=number_Odin_giup_do && number_Odin_giup_do<=5 )  number_Odin_giup_do++;
     if(number_Odin_giup_do == 6) number_Odin_giup_do =-1;
   }
   else {
     number_Odin_giup_do =-1;
   }

}

void Merlin(int &tinh_trang,int &level,int &HP,int &maxHP){
  if(tinh_trang == trung_doc ) tinh_trang = giai_doc;
  if(level < 10 ){
     level++;
     maxHP = (maxHP +100 >999)?999:maxHP+100;
  }
  HP = maxHP;
}

int tinh_yeu_vinh_cuu(int Lancelot,int Guinevere,int Excalibur,int hiepsi){
  if(Lancelot == 1 && Guinevere ==1 && Excalibur ==0) return 1;
  if(hiepsi == hiep_si_Arthur && Guinevere ==1 ) return 1;
  if(hiepsi == hiep_si_Lancelot && Guinevere==1) return 1;
  if(hiepsi == cong_chua_Guinevere && Lancelot ==1) return 1;
  return 0; 
}

void kiem_tra_kiem_Lionheart(int &kiem_Lionheart,int &number_Lionheart){

  if(0<=number_Lionheart && number_Lionheart<=5 )  number_Lionheart++;
if(number_Lionheart == 6) number_Lionheart =-1;
if(number_Lionheart != -1)  kiem_Lionheart=1;
else kiem_Lionheart = -1;
}

int tinh_giao_thua(int sukien){
  for(int i=sukien-1;i>0;i--)
  {
    sukien *=i;
  }
  return sukien;
}

void su_kien_mode_1(int bao_vat_thu_1,int bao_vat_thu_2,int bao_vat_thu_3,int &baovat1,int baovat2,int baovat3){
if(baovat1 != 1){
  if(bao_vat_thu_1<bao_vat_thu_2 && bao_vat_thu_1<bao_vat_thu_3) baovat1 =1;
  else if(bao_vat_thu_1>bao_vat_thu_2 && bao_vat_thu_1 > bao_vat_thu_3 && baovat2 && baovat3)  baovat1=1;
  else if(bao_vat_thu_1>bao_vat_thu_2 && baovat2) baovat1 =1;
  else if(bao_vat_thu_1>bao_vat_thu_3 && baovat3) baovat1=1;
}
  }

int kiem_tra_mode_hai_win(int giai_thua_su_kien, int *number_win_Ultimecia, int *arr_nPental)
{
  int max = 1;
  int vi_tri = 0;
  int co_roi = 0;
  for (int i = 0; i < giai_thua_su_kien; i++)
    if (number_win_Ultimecia[i] == 1)
    {
      if (arr_nPental[i] > max)
      {
        max = arr_nPental[i];
        vi_tri = i;
      }
      co_roi = 1;
    }
  if (co_roi != 0)
    return vi_tri;
  else
    return -1;
}

int kiem_tra_mode_hai_close(int giai_thua_su_kien, int *number_win_Ultimecia, int *arr_nPental)
{
  int max = 1;
  int vi_tri = 0;
  for (int i = 0; i < giai_thua_su_kien; i++)
    if (number_win_Ultimecia[i] > max)
    {
      max = arr_nPental[i];
      vi_tri = i;
    }
  return vi_tri;
}

struct vali
{
int hoa_hong;
int numberWin=0;
int numberClose=0;
int tinh_trang=giai_doc;
int number_Odin_giup_do =-1;
int number_thu_thach=-1;
int number_Lionheart=-1;
int than_Odin=con_song;
int maxHP;
int hiep_si;
int ao_giap_mythril=0;
int ao_SH=0;
int kiem_Lionheart=0;//0 la khong co 1 la co
int Excalibur=0;
int quai_vat_Omega=0;
int khien_Paladin=0;
int giao_Lancelot=0;
int toc_Guinevere=0;
int thu_tu_khien_Paladin;
int thu_tu_giao_Lancelot;
int thu_tu_toc_Guinevere;
};




report*  walkthrough (knight& theKnight, castle arrCastle[], int nCastle, int mode, int nPetal)
{

  report* pReturn;
  int bFlag;
  vali test;
  knight copy_theKnight = theKnight;
  test.hoa_hong=nPetal;
  test.maxHP=theKnight.HP;
  kiem_tra_hiep_si(theKnight.HP,test.hiep_si);
  if(test.hiep_si == hiep_si_Lancelot) test.giao_Lancelot=1;
  else if(test.hiep_si == cong_chua_Guinevere) test.toc_Guinevere=1;
  else if(test.hiep_si == hiep_si_Paladin) test.khien_Paladin=1;
  if( mode == 1) {
    test.thu_tu_khien_Paladin = ::hash(chiec_kien_Paladin);
    test.thu_tu_giao_Lancelot = ::hash(ngon_giao_Lancelot);
    test.thu_tu_toc_Guinevere = ::hash(soi_toc_Guinevere);
  } 
//mode ==2
  int arr_final[50]={0};
  int acount_arr=0;
  int sukien = nCastle;
  int giai_thua_su_kien = tinh_giao_thua(sukien);
  int arr_random[giai_thua_su_kien][sukien];
  int *arr_number_nPetal = new int[giai_thua_su_kien]{0};
  int *number_win_Ultimecia = new int[giai_thua_su_kien]{0};//1.0.1.1.0.....
  int acount_arrPental = -1;
  vali *arr_total_vali = new vali[giai_thua_su_kien];
  if (mode == 2)
  {
    int co_khac_nhau = 0;
    int cot_da_duoc_in = 0;

    for (int i = 0; i < giai_thua_su_kien; i++)
      for (int j = 0; j < sukien; j++)
        arr_random[i][j] = 100;

    int mang[sukien];
  vong_lap:
    for (int i = 0; i < sukien; i++)
    {
      mang[i] = rand() % sukien + 1;
      for (int j = 0; j < i; j++)
        for (int k = j + 1; k < sukien; k++)
          if (mang[j] == mang[k])
            goto vong_lap;
    }

    for (int i = 0; i < giai_thua_su_kien; i++)
    {
      for (int j = 0; j < sukien; j++)
        if (arr_random[i][j] != mang[j])
        {
          co_khac_nhau++;
          break;
        }
    }

    if (co_khac_nhau == giai_thua_su_kien)
      for (int j = 0; j < sukien; j++)
        arr_random[cot_da_duoc_in][j] = mang[j];
    else
    {
      co_khac_nhau = 0;
      goto vong_lap;
    }
    cot_da_duoc_in++;
    if (cot_da_duoc_in < giai_thua_su_kien)
    {
      co_khac_nhau = 0;
      goto vong_lap;
    }
  }
  //fighting for the existence of mankind here
int theEvent;
if(mode ==2){
    sau_khi_thua_chay_lan_hai:  
  for (int i = 0; i < giai_thua_su_kien; i++)
    {
    day_su_kien_lau_dai_tiep_theo:
    theKnight=copy_theKnight;
     vali test_mode_2 =test;
      if (++acount_arrPental == sukien)
        acount_arrPental = -1;
      for (int h = 0; h < nCastle; h++)
      {
        castle cc = arrCastle[arr_random[i][h] - 1];
        for (int j = 0; j < cc.nEvent; j++)
        {
          if (test_mode_2.hoa_hong == 0)
          {
            arr_number_nPetal[acount_arrPental] = test_mode_2.hoa_hong;
            arr_total_vali[i]=test_mode_2;
            i++;
            goto day_su_kien_lau_dai_tiep_theo;
          }
  theEvent = cc.arrEvent[j];
  test_mode_2.hoa_hong--;
  //kiem tra bien du so lan thi lay lai
  if(test_mode_2.hiep_si == hiep_si_Paladin && test_mode_2.number_Lionheart == 0) test_mode_2.kiem_Lionheart=1;
  else kiem_tra_kiem_Lionheart(test_mode_2.kiem_Lionheart,test_mode_2.number_Lionheart);
  Odin(test_mode_2.than_Odin,test_mode_2.number_Odin_giup_do);
  hinh_phat_Tornbery(test_mode_2.tinh_trang,theKnight.antidote,1,test_mode_2.number_thu_thach);
  //ket thu0,c kiem tra bien
  if(theEvent>=1 && theEvent<=5)
    {
      int baseDamge;
      int base_gil;

      if(theEvent==1) {baseDamge=1.0;base_gil=100;}
      else if(theEvent==2) {baseDamge=1.5;base_gil=150;}
      else if(theEvent == 3) {baseDamge=4.5;base_gil=450;}
      else if(theEvent==4) {baseDamge=6.5;base_gil=650;}
      else if(theEvent==5) {baseDamge=8.5;base_gil=850;}
      if(test.kiem_Lionheart==1 || test.hiep_si == hiep_si_Arthur || test.hiep_si == hiep_si_Lancelot || test.hiep_si == hiep_si_Paladin || (test.number_Odin_giup_do !=-1))
        {theKnight.gil = (theKnight.gil+base_gil >999)?999:(theKnight.gil+base_gil);test.numberWin++;}
      else if(test.tinh_trang == trung_doc){
            if(chien_dau(theKnight.level,j+1)) 
             {
               theKnight.gil = (theKnight.gil+base_gil >999)?999:(theKnight.gil+base_gil);
               test.numberWin++;
             }
            else 
            {//thua thi bi trua mau 1 lan
              test.numberClose++;
              if(test.ao_giap_mythril == 0) 
               if(hinh_phat(theKnight.HP,j+1,baseDamge) ==0)
                { 
                  callPhoenix(theKnight,test.maxHP);
                  if(test.tinh_trang == trung_doc ) test.tinh_trang =giai_doc;
                }
              }
           // if(test.ao_giap_mythril ||(theEvent==2 && test.hiep_si == cong_chua_Guinevere)) continue;
            //hinh phat khi trung doc la tru mau them 1 lan nua
            if(hinh_phat(theKnight.HP,j+1,baseDamge) ==0)
              { 
                callPhoenix(theKnight,test.maxHP);
                if(test.tinh_trang == trung_doc ) test.tinh_trang =giai_doc;
              }

            }
      else if(chien_dau(theKnight.level,j+1))
            {theKnight.gil = (theKnight.gil+base_gil >999)?999:(theKnight.gil+base_gil);test.numberWin++;}
      else {
            test.numberClose++;
            if(test.ao_giap_mythril ||(theEvent==2 && test.hiep_si == cong_chua_Guinevere)) continue;
            if(hinh_phat(theKnight.HP,j+1,baseDamge) ==0)
            {
                callPhoenix(theKnight,test.maxHP);
                if(test.tinh_trang == trung_doc ) test.tinh_trang =giai_doc;
            }
          }
        continue;
    }

  switch (theEvent)
{
  case Tornbery:
if(test.tinh_trang == trung_doc ) break;
else {
 if( chien_dau(theKnight.level,j+1) || test.kiem_Lionheart ==1 || test.number_Odin_giup_do !=-1 || test.hiep_si == hiep_si_Arthur|| test.hiep_si == hiep_si_Lancelot) 
     {increa_level(theKnight.level,test.maxHP);test.numberWin++;}
 else{
    test.numberClose++;
    if(test.hiep_si == hiep_si_Paladin || test.hiep_si == hiep_si_rong) 
     {
       if(theKnight.antidote != 0) theKnight.antidote--;
       break;
     }
    test.number_thu_thach=0;
    hinh_phat_Tornbery(test.tinh_trang,theKnight.antidote,3,test.number_thu_thach);
 }
}
break;
case Queen_of_Cards:
if(chien_dau(theKnight.level,j+1) || test_mode_2.hiep_si == hiep_si_Paladin || test_mode_2.hiep_si == hiep_si_rong ||test_mode_2.number_Odin_giup_do !=-1)
   {theKnight.gil = (theKnight.gil*2 >999)?999:theKnight.gil*2;test_mode_2.numberWin++;}
else {
  test_mode_2.numberClose++;
  if(test_mode_2.hiep_si == cong_chua_Guinevere || test_mode_2.ao_SH ==1) break;
  theKnight.gil = (int) theKnight.gil/2;
}
break;
case Nina_de_Rings:
if(test_mode_2.hiep_si == cong_chua_Guinevere || test_mode_2.ao_SH ==1 || friendly_number(theKnight.HP,theKnight.gil) || test_mode_2.hiep_si == hiep_si_Paladin)
  {
    gap_Nina(theKnight.gil,test_mode_2.tinh_trang,theKnight.HP,test_mode_2.maxHP,1);
    if(test_mode_2.hiep_si == cong_chua_Guinevere) theKnight.gil +=50;
  }
else 
  gap_Nina(theKnight.gil,test_mode_2.tinh_trang,theKnight.HP,test_mode_2.maxHP,0);
if(friendly_number(theKnight.HP,theKnight.gil)) 
{
 test_mode_2.number_Lionheart=0; 
}
break;
case nhat_antidote:
if(++theKnight.antidote>99) theKnight.antidote=99;
break;
case gap_Odin:
if(test_mode_2.than_Odin == da_chet) break;
else test_mode_2.number_Odin_giup_do=0;
break;
case gap_phu_thuy_Merlin:
Merlin(test_mode_2.tinh_trang,theKnight.level,theKnight.HP,test_mode_2.maxHP);
break;
case quai_vat_Omega_Weapon:
if(test_mode_2.quai_vat_Omega = da_chet) break;
if((theKnight.level==10 && test_mode_2.Excalibur ==1)|| (test_mode_2.hiep_si == hiep_si_rong && test_mode_2.kiem_Lionheart ==1))
{
    theKnight.level=10;
    theKnight.gil = 999;
  }
  else {
    if(test_mode_2.ao_giap_mythril == 1) break;
    callPhoenix(theKnight,test_mode_2.maxHP);
    if(test_mode_2.tinh_trang == trung_doc) test_mode_2.tinh_trang = giai_doc;
  }

break;
case than_chet_Hades:
if(test_mode_2.number_Odin_giup_do!= -1) if(test_mode_2.hiep_si == hiep_si_rong) {test_mode_2.ao_giap_mythril=1;break;}
                             else test_mode_2.than_Odin = da_chet;
if(chien_dau(theKnight.level,j+1) || test_mode_2.kiem_Lionheart  == 1 || tinh_yeu_vinh_cuu(test_mode_2.giao_Lancelot,test_mode_2.toc_Guinevere,test_mode_2.Excalibur,test_mode_2.hiep_si) || (test_mode_2.number_Odin_giup_do !=-1 && test_mode_2.hiep_si == hiep_si_rong))
   test_mode_2.ao_giap_mythril =1;
else{
  if(test_mode_2.ao_giap_mythril == 1) break;//ao giap van anh huong den su kien do khi co ao giap thi khong bi mat mau chet de goi phuong hoang ra giup do giai doc duoc
  callPhoenix(theKnight,test_mode_2.maxHP);
  if(test_mode_2.tinh_trang == trung_doc) test_mode_2.tinh_trang = giai_doc;
}
break;
case nhat_Scarlet_Hakama:
test_mode_2.ao_SH =1;
break;
case cong_LockedDoor:
if(theKnight.level<=(j+1)%10) {goto ra_khoi_lau_dai_mode_2;}
break;
case chiec_kien_Paladin:
if(test_mode_2.khien_Paladin ==1) break;
else 
  test_mode_2.khien_Paladin =1;
break;
case ngon_giao_Lancelot:
if(test_mode_2.giao_Lancelot ==1) break;
else
  test_mode_2.giao_Lancelot =1;
break;
case soi_toc_Guinevere:
if(test_mode_2.toc_Guinevere ==1) break;
else
  test_mode_2.toc_Guinevere =1;
break;
case guom_Excalibur:
if(test_mode_2.hiep_si == hiep_si_Arthur) {test_mode_2.Excalibur=1;break;}
if(test_mode_2.khien_Paladin && test_mode_2.giao_Lancelot && test_mode_2.toc_Guinevere)
test_mode_2.Excalibur=1;
break;
case gap_Ultimecia:
if(test_mode_2.Excalibur || test_mode_2.kiem_Lionheart ==1 )
{
  number_win_Ultimecia[i] = 1;
  arr_number_nPetal[acount_arrPental] = test_mode_2.hoa_hong;
  arr_total_vali[i]=test_mode_2;  
  i++;
goto day_su_kien_lau_dai_tiep_theo;
}

break;
}
/**************/
}

ra_khoi_lau_dai_mode_2:increa_level(theKnight.level,test_mode_2.maxHP);
}
       arr_total_vali[i]=test_mode_2;
       arr_number_nPetal[acount_arrPental] = test_mode_2.hoa_hong;
       }

           if(kiem_tra_mode_hai_win(giai_thua_su_kien,number_win_Ultimecia,arr_number_nPetal) != -1) 
           {
             for(int i=0;i<giai_thua_su_kien;i++)
             arr_final[acount_arr++]=arr_random[kiem_tra_mode_hai_win(giai_thua_su_kien,number_win_Ultimecia,arr_number_nPetal)][i];
             goto chay_het_chay_lai_mode_2;
           }
        else {
//ham nay tra ve vi tri ne coi chay di roi ngoang lai day vi chua co win
for(int i=0;i<giai_thua_su_kien;i++){
arr_total_vali[i]=arr_total_vali[kiem_tra_mode_hai_close(giai_thua_su_kien,number_win_Ultimecia,arr_number_nPetal)];
arr_final[acount_arr++]=arr_random[kiem_tra_mode_hai_close(giai_thua_su_kien,number_win_Ultimecia,arr_number_nPetal)][i];
}
goto sau_khi_thua_chay_lan_hai;
        }  
// 
//if(test_mode_2.hoa_hong == 0 && test_mode_2.hiep_si == hiep_si_Arthur) goto chay_het_chay_lai;
// ket_thuc: 
  //  if(test_mode_2.hoa_hong == 0 && test_mode_2.hiep_si == hiep_si_Arthur) bFlag=1;
  //  else if(test_mode_2.hoa_hong==0) bFlag=0;
  //  else bFlag=1;


}

/**mode =0 ............................................mode =1**/
if(mode == 0 || mode ==1 ){
  chay_het_chay_lai_mode_2:
  if(mode ==2 ) nCastle=acount_arr;//do xai goto
  theKnight=copy_theKnight;
  chay_het_chay_lai:
  for (int i = 0; i < nCastle; i++)
{
  castle cc =(mode==2)?arrCastle[arr_final[i]-1]:arrCastle[i];
 for (int j = 0; j < cc.nEvent; j++)
{ 
  if(test.hoa_hong == -1 && test.hiep_si != hiep_si_Arthur)  goto ket_thuc;
  if(test.hoa_hong == 0 && test.hiep_si == hiep_si_Arthur) ;
  else
  if(test.hoa_hong != -1) test.hoa_hong--;
  theEvent = cc.arrEvent[j];
  //kiem tra bien du so lan thi lay lai
   if(test.hiep_si == hiep_si_Paladin && test.number_Lionheart == 0) test.kiem_Lionheart=1;
 else kiem_tra_kiem_Lionheart(test.kiem_Lionheart,test.number_Lionheart);
  Odin(test.than_Odin,test.number_Odin_giup_do);
  hinh_phat_Tornbery(test.tinh_trang,theKnight.antidote,1,test.number_thu_thach);
  //ket thu0,c kiem tra bien

  if(theEvent>=1 && theEvent<=5)
    {
      int baseDamge;
      int base_gil;

      if(theEvent==1) {baseDamge=1.0;base_gil=100;}
      else if(theEvent==2) {baseDamge=1.5;base_gil=150;}
      else if(theEvent == 3) {baseDamge=4.5;base_gil=450;}
      else if(theEvent==4) {baseDamge=6.5;base_gil=650;}
      else if(theEvent==5) {baseDamge=8.5;base_gil=850;}
      if(test.kiem_Lionheart==1 || test.hiep_si == hiep_si_Arthur || test.hiep_si == hiep_si_Lancelot || test.hiep_si == hiep_si_Paladin || (test.number_Odin_giup_do !=-1))
        {theKnight.gil = (theKnight.gil+base_gil >999)?999:(theKnight.gil+base_gil);test.numberWin++;}
      else if(test.tinh_trang == trung_doc){
            if(chien_dau(theKnight.level,j+1)) 
             {
               theKnight.gil = (theKnight.gil+base_gil >999)?999:(theKnight.gil+base_gil);
               test.numberWin++;
             }
            else 
            {//thua thi bi trua mau 1 lan
              test.numberClose++;
              if(test.ao_giap_mythril == 0) 
               if(hinh_phat(theKnight.HP,j+1,baseDamge) ==0)
                { 
                  callPhoenix(theKnight,test.maxHP);
                  if(test.tinh_trang == trung_doc ) test.tinh_trang =giai_doc;
                }
              }
           // if(test.ao_giap_mythril ||(theEvent==2 && test.hiep_si == cong_chua_Guinevere)) continue;
            //hinh phat khi trung doc la tru mau them 1 lan nua
            if(hinh_phat(theKnight.HP,j+1,baseDamge) ==0)
              { 
                callPhoenix(theKnight,test.maxHP);
                if(test.tinh_trang == trung_doc ) test.tinh_trang =giai_doc;
              }

            }
      else if(chien_dau(theKnight.level,j+1))
            {theKnight.gil = (theKnight.gil+base_gil >999)?999:(theKnight.gil+base_gil);test.numberWin++;}
      else {
            test.numberClose++;
            if(test.ao_giap_mythril ||(theEvent==2 && test.hiep_si == cong_chua_Guinevere)) continue;
            if(hinh_phat(theKnight.HP,j+1,baseDamge) ==0)
            {
                callPhoenix(theKnight,test.maxHP);
                if(test.tinh_trang == trung_doc ) test.tinh_trang =giai_doc;
            }
          }
        continue;
    }
  if(mode ==1 && (theEvent == chiec_kien_Paladin || theEvent == ngon_giao_Lancelot || theEvent == soi_toc_Guinevere))
  {
     if(theEvent == chiec_kien_Paladin) su_kien_mode_1(test.thu_tu_khien_Paladin,test.thu_tu_toc_Guinevere,test.thu_tu_giao_Lancelot,test.khien_Paladin,test.toc_Guinevere,test.giao_Lancelot);
     else if(theEvent == ngon_giao_Lancelot) su_kien_mode_1(test.thu_tu_giao_Lancelot,test.thu_tu_khien_Paladin,test.thu_tu_toc_Guinevere,test.giao_Lancelot,test.khien_Paladin,test.toc_Guinevere);
     else if(theEvent == soi_toc_Guinevere) su_kien_mode_1(test.thu_tu_toc_Guinevere,test.thu_tu_khien_Paladin,test.thu_tu_giao_Lancelot,test.toc_Guinevere,test.khien_Paladin,test.giao_Lancelot);
    continue;
  }

  switch (theEvent)
{
case Tornbery:
if(test.tinh_trang == trung_doc ) break;
else {
 if( chien_dau(theKnight.level,j+1) || test.kiem_Lionheart ==1 || test.number_Odin_giup_do !=-1 || test.hiep_si == hiep_si_Arthur|| test.hiep_si == hiep_si_Lancelot) 
     {increa_level(theKnight.level,test.maxHP);test.numberWin++;}
 else{
    test.numberClose++;
    if(test.hiep_si == hiep_si_Paladin || test.hiep_si == hiep_si_rong) 
     {
       if(theKnight.antidote != 0) theKnight.antidote--;
       break;
     }
    test.number_thu_thach=0;
    hinh_phat_Tornbery(test.tinh_trang,theKnight.antidote,3,test.number_thu_thach);
 }
}
break;
case Queen_of_Cards:
if(chien_dau(theKnight.level,j+1) || test.hiep_si == hiep_si_Paladin || test.hiep_si == hiep_si_rong ||test.number_Odin_giup_do !=-1 || test.hiep_si == hiep_si_Arthur|| test.hiep_si == hiep_si_Lancelot)
   {theKnight.gil = (theKnight.gil*2 >999)?999:theKnight.gil*2;test.numberWin++;}
else {
  test.numberClose++;
  if(test.hiep_si == cong_chua_Guinevere || test.ao_SH ==1) break;
  theKnight.gil = (int) theKnight.gil/2;
}
break;
case Nina_de_Rings:
if(test.hiep_si == cong_chua_Guinevere || test.ao_SH ==1 || friendly_number(theKnight.HP,theKnight.gil) || test.hiep_si == hiep_si_Paladin)
  {
    gap_Nina(theKnight.gil,test.tinh_trang,theKnight.HP,test.maxHP,1);
    if(test.hiep_si == cong_chua_Guinevere) theKnight.gil = (theKnight.gil+50 >999)?999:theKnight.gil+50;
  }
else 
  gap_Nina(theKnight.gil,test.tinh_trang,theKnight.HP,test.maxHP,0);
if(friendly_number(theKnight.HP,theKnight.gil)) 
{
 test.number_Lionheart=0;
 //kiem_tra_kiem_Lionheart(&kiem_Lionheart,&number_Lionheart); 
}
 
break;
case vuong_sau_rieng:
vuon_sau_rieng(test.tinh_trang,theKnight.HP,test.maxHP,test.hoa_hong,test.ao_SH);
break;
case nhat_antidote:
if(++theKnight.antidote>99) theKnight.antidote=99;
break;
case gap_Odin:
if(test.than_Odin == da_chet) break;
else {
test.number_Odin_giup_do=0;
//Odin(tinh_trang,&number_Odin_giup_do);
}
break;
case gap_phu_thuy_Merlin:
Merlin(test.tinh_trang,theKnight.level,theKnight.HP,test.maxHP);
break;
case quai_vat_Omega_Weapon:
if(test.quai_vat_Omega = da_chet) break;
if((theKnight.level==10 && test.Excalibur ==1)|| (test.hiep_si == hiep_si_rong && test.kiem_Lionheart ==1))
{
  test.numberWin++;
  if(theKnight.level<10){
    test.maxHP = (test.maxHP+100*(10-theKnight.level)>999)?999:test.maxHP+100*(10-theKnight.level);
    theKnight.level=10;
    theKnight.gil = 999;
  }
}
  else {
    test.numberClose--;
    if(test.ao_giap_mythril == 1) break;
    callPhoenix(theKnight,test.maxHP);
    if(test.tinh_trang == trung_doc) test.tinh_trang = giai_doc;
  }

break;
case than_chet_Hades:
if(test.number_Odin_giup_do!= -1) if(test.hiep_si == hiep_si_rong) {test.ao_giap_mythril=1;break;}
                             else test.than_Odin = da_chet;
if(chien_dau(theKnight.level,j+1) || test.kiem_Lionheart || tinh_yeu_vinh_cuu(test.giao_Lancelot,test.toc_Guinevere,test.Excalibur,test.hiep_si) || (test.number_Odin_giup_do !=-1 && test.hiep_si == hiep_si_rong))
   {test.ao_giap_mythril =1;test.numberWin++;}
else{
  test.numberClose++;
  if(test.ao_giap_mythril == 1) break;
  callPhoenix(theKnight,test.maxHP);
  if(test.tinh_trang == trung_doc) test.tinh_trang = giai_doc;
}
break;
case nhat_Scarlet_Hakama:
test.ao_SH =1;
break;
case cong_LockedDoor:
if(test.hiep_si == hiep_si_rong || test.hiep_si == hiep_si_Lancelot) break;
if(theKnight.level<=(j+1)%10) {goto ra_khoi_lau_dai;}
break;
case chiec_kien_Paladin:
if(test.khien_Paladin ==1) break;
else 
  test.khien_Paladin =1;
break;
case ngon_giao_Lancelot:
if(test.giao_Lancelot ==1) break;
else
  test.giao_Lancelot =1;
break;
case soi_toc_Guinevere:
if(test.toc_Guinevere ==1) break;
else
  test.toc_Guinevere =1;
break;
case guom_Excalibur:
//them cai phan arthirl co the rut kiem ma khong can du ba bao vat
if(test.hiep_si == hiep_si_Arthur) {test.Excalibur=1;break;}
if(test.khien_Paladin && test.giao_Lancelot && test.toc_Guinevere)
test.Excalibur=1;
break;
case gap_Ultimecia:
if(test.tinh_trang == trung_doc) theKnight.HP = (theKnight.HP < 3)?1:(int)theKnight.HP/3;
if(test.Excalibur || test.kiem_Lionheart)
{
  test.numberWin++;
  goto ket_thuc;
}
else {
  test.numberClose++;
  if(test.hiep_si == cong_chua_Guinevere) break;//phai tach rieng do cong chua van tinh la thua
  if(test.ao_giap_mythril != 1) theKnight.HP = (theKnight.HP < 3)?1:(int)theKnight.HP/3;
  }

break;
}
/**************/
}

ra_khoi_lau_dai:increa_level(theKnight.level,test.maxHP);
}
if(test.hoa_hong!=0) goto chay_het_chay_lai;
if(test.hoa_hong == 0 && test.hiep_si == hiep_si_Arthur) goto chay_het_chay_lai;
ket_thuc:
   if(test.hoa_hong == 0 && test.hiep_si == hiep_si_Arthur) bFlag=1;
   else if(test.hoa_hong== -1) bFlag=0;
   else bFlag=1;

}

/**mode =0 ............................................mode =1**/
  // success or failure?	
  if(bFlag){
    pReturn = new report;
    pReturn->nPetal=test.hoa_hong;
pReturn->nWin=test.numberWin;
pReturn->nLose=test.numberClose;
  }
  else pReturn=NULL;
  delete[] arr_number_nPetal,number_win_Ultimecia,arr_total_vali;
  return pReturn;
}