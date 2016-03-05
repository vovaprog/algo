#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Gadget{
public:    
    long long int number;
    long long int price;
};

int main()
{
    long long int totalDays, totalGads, neededGads, totalMoney;
    
    cin >>totalDays>>totalGads>>neededGads>>totalMoney;    
    
    vector<Gadget> gadsD;
    vector<Gadget> gadsF;
    vector<long long int> ratesD(totalDays), ratesF(totalDays);
    
    for(int i=0;i<totalDays;i++)
    {
        cin >> ratesD[i];    
    }
    
    for(int i=0;i<totalDays;i++)
    {
        cin >> ratesF[i];
    }
    
    for(int i=0;i<totalGads;i++)
    {
        int cur, price;
        cin >> cur >> price;

        Gadget g;
        g.number = i+1;
        g.price = price;
        
        if(cur==1)
        {
            gadsD.push_back(g);    
        }
        else            
        {
            gadsF.push_back(g);    
        }
    }
    
    sort(gadsD.begin(), gadsD.end(), 
        [](const Gadget &g0,const Gadget &g1)
        {
            return g0.price < g1.price;    
        });
    sort(gadsF.begin(), gadsF.end(),
        [](const Gadget &g0,const Gadget &g1)
        {
            return g0.price < g1.price;    
        });        
    
    long long int minRateF = -1;
    long long int minRateD = -1;
    long long int minRateFDay = -1;
    long long int minRateDDay = -1;
    
    for(int day=0;day<totalDays;day++)
    {        
        bool check = false;
        
        if(day==0)
        {
            minRateD = ratesD[0];
            minRateF = ratesF[0];
            minRateFDay = minRateDDay = 0;
            check = true;
        }
        
        if(ratesD[day]<minRateD)
        {
            minRateD = ratesD[day];
            minRateDDay = day;
            check = true;
        }
        
        if(ratesF[day]<minRateF)
        {
            minRateF = ratesF[day];
            minRateFDay = day;
            check = true;
        }
        
        if(check)
        {
            int count = 0;
            int di=0, fi=0;
            long long int money = totalMoney;
            vector<int> gD;
            vector<int> gF;
            
            while(di<gadsD.size() || fi<gadsF.size())
            {
                long long int priceD=-1, priceF=-1;
                if(di<gadsD.size())
                {
                    priceD = gadsD[di].price * minRateD;
                }
                if(fi<gadsF.size())
                {
                    priceF = gadsF[fi].price * minRateF;    
                }
                
                bool buyFlag=false;
                if(priceD>0 && (priceF<0 || priceD <= priceF) && money>=priceD)
                {                    
                    money -= priceD;
                    gD.push_back(gadsD[di].number);
                    count++;
                    di++;
                    buyFlag=true;
                }
                else if(priceF>0 && (priceD<0 || priceF <= priceD) && money >= priceF)
                {   
                    money -= priceF;
                    gF.push_back(gadsF[fi].number);
                    count++;
                    fi++;
                    buyFlag=true;
                }
                                
                if(count >= neededGads || money <= 0 || !buyFlag) break; 
            }
            
            if(count >= neededGads)
            {
                cout << day+1 << endl;
                for(auto& g : gD)
                {
                    cout << g << " " << minRateDDay+1 << endl;    
                }
                for(auto& g : gF)
                {
                    cout << g << " " << minRateFDay+1 << endl;    
                }                
                return 0;
            }
        }
    }

    cout << -1;
    
    return 0;    
}

