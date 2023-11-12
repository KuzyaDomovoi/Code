#include <vector>
#include <random>
#include <time.h>
#include <iostream>

class CRandGen
{
public:
   static std::string RandWord(size_t nMinLen, size_t nMaxLen, bool bStartUpper = false, bool bRandUpper = false);
   static int Rand(int nMin, int nMax);
   static bool RandBool();
   static std::string MkRandText(int nMinSentWords, int nMaxSentWords, int nMinSents, int nMaxSents);
};

std::string CRandGen::RandWord(size_t nMinLen, size_t nMaxLen, bool bStartUpper/*=false*/, bool bRandUpper/*=false*/)
{
   /*http://planetozh.com/blog/2012/10/generate-random-pronouceable-words/ */
  
   std::string Word;
   std::string Add;

   const std::vector<const char*> cons_start =
   {
      /*single consonants. Beware of Q, it's often awkward in words*/"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "x", "z",
      /*possible combinations excluding those which cannot start a word*/ "pt", "gl", "gr", "ch", "ph", "ps", "sh", "st", "th", "wh"
   };
   const std::vector<const char*> cons_all =
   {
      /*single consonants. Beware of Q, it"s often awkward in words*/ "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "x", "z",
      /*possible combinations excluding those which cannot start a word*/ "pt", "gl", "gr", "ch", "ph", "ps", "sh", "st", "th", "wh", "ck", "cm", "dr", "ds", "ft", "gh", "gn",
      "kr", "ks", "ls", "lt", "lr", "mp", "mt", "ms", "ng", "ns", "rd", "rg", "rs", "rt", "ss", "ts", "tch"
   };

   const std::vector<const char*> vows =
   {
      /*single vowels*/ "a", "e", "i", "o", "u", "y",
      /*vowel combinations your language allows*/ "ee", "oa", "oo"
   };

   size_t len = Rand(nMinLen, nMaxLen);
   bool bIsVow = RandBool();
   auto GetRandomV = [cons_start, cons_all, vows, &bIsVow, &Word]()->const char*{const auto &pCur = (bIsVow ? vows : (Word.empty() ? cons_start : cons_all)); size_t indx = Rand(0,pCur.size()-1); return pCur[indx];};

   while (Word.length() < len){Add = GetRandomV(); if (Word.length() + Add.length() <= len){Word += Add;bIsVow = !bIsVow;}}  
   if (bRandUpper){for (auto &s : Word){if (RandBool()){s = toupper(s);}}}
   if (bStartUpper){if (Word.length() > 0){ Word[0] = toupper(Word[0]);}}
   return Word;
}

int CRandGen::Rand(int nMin, int nMax)
{
   std::random_device rd;
   if (nMax < nMin){std::swap(nMin, nMax);}

   static std::mt19937 gen(time(0));
   std::uniform_int_distribution<int> uid1(nMin, nMax);
   return uid1(gen);

   //   return uid1.();
}

bool CRandGen::RandBool()
{
   return Rand(0, 1);
}

std::string CRandGen::MkRandText(int nMinSentWords, int nMaxSentWords, int nMinSents, int nMaxSents)
{
   std::string sText;
   size_t nNumSents = Rand(nMinSents, nMaxSents),nCurSents=0;
   size_t nCurSentLen = 0, nCurSentMaxLen = Rand(nMinSentWords, nMaxSentWords);
   bool bFirstWord = true;
   bool bLineEnd;
   char RNum[20];
   bool bIsQuoteOpen=false;
   do
   {
      
      sText+=RandWord(3, 8, bFirstWord, false);
      bFirstWord = false;
      ;
      if (nCurSentLen++ > nCurSentMaxLen)
      {
         nCurSentLen = 0;
         nCurSentMaxLen = Rand(nMinSentWords, nMaxSentWords);
         bLineEnd = true;// RandBool();
         switch (Rand(0,4))
         {
            case 0:
            {
               sText += ",";
               bLineEnd = false;
               break;
            }
            default:
            {
               sText += ".";
               bFirstWord = true;
               nNumSents--;
               break;
            }
            case 2:
            {
               sText += "?";
               bFirstWord = true;
               nNumSents--;
               break;
            }
            case 3:
            {
               sText += "?!";
               bFirstWord = true;
               nNumSents--;
               break;
            }
         }
         if (nNumSents)
         {
            sText += bLineEnd ? "\n" : " ";
            /*if(bLineEnd)
            {
               sprintf(RNum, "%i", Rand(162006000, 162006255));
               sText += "\n>>";
               sText += RNum;
               sText += "\n";
            }*/
         }

      }
      else
      {
         sText += " ";
      }
   }
   while (nNumSents);

   return sText;
}

int main()
{
       auto s=CRandGen::MkRandText(4, 16, 60, 90);
       std::cout<<s<<std::endl<<"________"<<std::endl;	
	return 0;
}
