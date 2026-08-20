#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
public:

    // ✅ 1. دالة عامة للتحقق من أن الرقم ضمن مجال
    template <typename T>
    static bool IsNumberBetween(T Number, T From, T To)
    {
        return (Number >= From && Number <= To);
    }

    // ✅ 2. دالة عامة لقراءة رقم من نوع T
    template <typename T>
    static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        T Number;
        cin >> Number;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
            cin >> Number;
        }

        return Number;
    }

    // ✅ 3. دالة عامة لقراءة رقم ضمن مدى باستخدام الدالتين السابقتين
    template <typename T>
    static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        T Number = ReadNumber<T>();

        while (!IsNumberBetween<T>(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadNumber<T>();
        }

        return Number;
    }

    // ✅ 4. التحقق من صحة التاريخ (ثابت)
    static bool IsValideDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

    // ✅ 5. التحقق من أن التاريخ ضمن مجال (ثابت - لا يمكن تحويله لـ template بسهولة)
    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        // Date >= From && Date <= To
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
            &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
        {
            return true;
        }

        // Date >= To && Date <= From
        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
            &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
        {
            return true;
        }

        return false;
    }

    // ✅ 6. قراءة نص (غير قابلة للـ template)
    static string ReadString()
    {
        string S1 = "";
        getline(cin >> ws, S1);
        return S1;
    }
};
