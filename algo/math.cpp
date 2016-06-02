
//Умножение чисел по модулю 677c
inline int64 mul_modul(int64 x, int64 y, int64 modul)
{
    return ((x % modul) * (y % modul)) % modul;
}

//Возведение в степень по модулю 677c
inline int64 power_modul(int64 base, int64 pwr, int64 modul)
{
    int64 result = 1;
    
    for(int i=1; i<=pwr; ++i)
    {
        result = mul_modul(result, base, modul);
    }
    
    return result;
}
