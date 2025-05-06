#include<bits/stdc++.h>
using namespace std;


// Percentage Range	             Letter Grade	        Grade Point
// 90% and above	                     A+	                 10
// 80% to less than 90%	                 A	                 9
// 70% to less than 80%	                 B	                 8
// 60% to less than 70%	                 C	                 7
// 50% to less than 60%	                 D	                 6
// 35% to less than 50%	                 P (Pass)	         5
// Below 35% (Theory)	                 F (Fail)	         0
// Below 40% (Sessional/Practical)    	 F (Fail)	         0

int AA = 10, A = 9, B = 8, C = 7, D = 6, P = 5, F = 0;

int Num_External, Num_Internal, Sub; 
string Subject_External;

vector<float>External_percent_Arr;
vector<float>Internal_percent_Arr;

vector<float>Arr_Grade_Point_External;
vector<float>Arr_Grade_Point_Internal;

//Array for Subject Name and Subject of External and Internal.
vector<string> Arr_Subject_Name_External;
vector<string> Arr_Subject_Name_Internal;

//Marks you Supposing to Get in External and Internal.
vector<int> Marks_Get_External_Arr;
vector<int> Marks_Get_Internal_Arr;
vector<int> Max_Marks_External_Arr;
vector<int> Max_Marks_Internal_Arr;

//Array for Subject Credit point and Number you get.
vector<int> External_Subject_CreditPoint;
vector<int> Internal_Subject_CreditPoint;


//Input External Subject Number and Names.
void SubjectName_External(){
    cout<<"Enter How many Subject you have in External Exam : ";
    cin>>Num_External;
    for(int i = 0; i < Num_External; i++){
        cout<<"Enter "<<i+1<<" Subjects names : ";
        cin>>Subject_External;
        Arr_Subject_Name_External.push_back(Subject_External);
    }
}

//Taking Input of Maximum Marks For which exam is conducted.
int Maximum_External_Marks;
void MaxMarksExternal(){
    for(int i = 0; i < Num_External; i++){
        cout<<"Enter Maximum Marks for which Exam is conducted for "<<Arr_Subject_Name_External[i]<<" : "; 
        cin>>Maximum_External_Marks;
        Max_Marks_External_Arr.push_back(Maximum_External_Marks);
    }
}


//External Marks Suppose You Get.
int MarksObtained_External(){
    for(int i = 0; i < Num_External; i++){
        cout<<"Enter Your Subject Marks You're expecting "<<Arr_Subject_Name_External[i]<<" : ";
        cin>>Sub;
        Marks_Get_External_Arr.push_back(Sub);
    }
}

float Percent_External;
float PercentageOfExternal(){
    for(int i = 0; i < Num_External; i++){
       Percent_External = (static_cast<float>(Marks_Get_External_Arr[i]) / Max_Marks_External_Arr[i])*100;
       if(Percent_External >= 90.0) External_percent_Arr.push_back(AA);
       else if(Percent_External >= 80.0 && Percent_External < 90.0) External_percent_Arr.push_back(A);
       else if(Percent_External >= 70.0 && Percent_External < 80.0) External_percent_Arr.push_back(B);
       else if(Percent_External >= 60.0 && Percent_External < 70.0) External_percent_Arr.push_back(C);
       else if(Percent_External >= 50.0 && Percent_External < 60.0) External_percent_Arr.push_back(D);
       else if(Percent_External >= 35.0 && Percent_External < 50.0) External_percent_Arr.push_back(P);
       else External_percent_Arr.push_back(F);
    }
}

//External Total Marks
int SumExternalMarks = 0;
int SumOfExternalMarks(){
    for(int i = 0; i < Marks_Get_External_Arr.size(); i++){
      SumExternalMarks = SumExternalMarks + Marks_Get_External_Arr[i]; 
    }
}

//External Credit Input.
int CreditPoint_External;
int Credit_External(){
    for(int i = 0; i < Num_External; i++){
        cout<<"Enter the Credit points of  "<<Arr_Subject_Name_External[i]<<": ";
        cin>>CreditPoint_External;
        External_Subject_CreditPoint.push_back(CreditPoint_External);
    }
}
//Total External Credit Points.
float SumExternalCreditMarks = 0;
int SumOfExternalCreditMarks(){
    for(int i = 0; i < Marks_Get_External_Arr.size(); i++){
      SumExternalCreditMarks += External_Subject_CreditPoint[i]; 
    }
}

float Grade_Point_External;
float Grade_External(){
    for(int i = 0; i < Num_External; i++){
       Grade_Point_External = External_Subject_CreditPoint[i] * External_percent_Arr[i];
       Arr_Grade_Point_External.push_back(Grade_Point_External);
    }
}

float SumExternal_GradePoint = 0.0;
float Sum_Of_External_GradePoint(){
    for(int i = 0; i < Arr_Grade_Point_External.size(); i++){
        SumExternal_GradePoint = SumExternal_GradePoint + Arr_Grade_Point_External[i];
    }
}

//Internal No of Subject.
string Subject_Internal;
int SubjectName_Internal(){
    cout<<"Enter How many Subject you have in Your Internal Or Viva : ";
    cin>>Num_Internal;
    for(int i = 0; i < Num_Internal; i++){
        cout<<"Enter "<<i+1<<" Subjects names : ";
        cin>>Subject_Internal;
        Arr_Subject_Name_Internal.push_back(Subject_Internal);
    }
}

//Input of  Internal Marks for which exam is conducted.
int Maximum_Internal_Marks;
int MaxMarksInternal(){
    for(int i = 0; i < Num_Internal; i++){
       cout<<"Enter Maximum Marks for which Exam is conducted :  "<<Arr_Subject_Name_Internal[i]<<" : "; 
       cin>>Maximum_Internal_Marks;
       Max_Marks_Internal_Arr.push_back(Maximum_Internal_Marks);
    }
}

//Sum Of Internal Marks for which exam is conducted.

//Internal Marks You Expected to get.
int MarksObtained_Internal(){
    for(int i = 0; i < Num_Internal; i++){
        cout<<"Enter Your Subject Marks You're expecting "<<Arr_Subject_Name_Internal[i]<<" : ";
        cin>>Sub;
        Marks_Get_Internal_Arr.push_back(Sub);
    }
}

//Internal Total Marks
int SumInternalMarks = 0;
int SumOfInternalMarks(){
    for(int i = 0; i < Marks_Get_Internal_Arr.size(); i++){
      SumInternalMarks += Marks_Get_Internal_Arr[i]; 
    }
}

float Percent_Internal;
float PercentageOfInternal(){
    for(int i = 0; i < Num_Internal; i++){
       Percent_Internal = (static_cast<float>(Marks_Get_Internal_Arr[i]) / Max_Marks_Internal_Arr[i])*100;
       if(Percent_Internal >= 90.0) Internal_percent_Arr.push_back(AA);
       else if(Percent_Internal >= 80.0 && Percent_Internal < 90.0) Internal_percent_Arr.push_back(A);
       else if(Percent_Internal >= 70.0 && Percent_Internal < 80.0) Internal_percent_Arr.push_back(B);
       else if(Percent_Internal >= 60.0 && Percent_Internal < 70.0) Internal_percent_Arr.push_back(C);
       else if(Percent_Internal >= 50.0 && Percent_Internal < 60.0) Internal_percent_Arr.push_back(D);
       else if(Percent_Internal >= 35.0 && Percent_Internal < 50.0) Internal_percent_Arr.push_back(P);
       else Internal_percent_Arr.push_back(F);
    }
}


//Internal Credit Input.
int CreditPoint_Internal;
int Credit_Internal(){
    for(int i = 0; i < Num_Internal; i++){
        cout<<"Enter the Credit points of Enternal Subjects "<<Arr_Subject_Name_Internal[i]<<": ";
        cin>>CreditPoint_Internal;
        Internal_Subject_CreditPoint.push_back(CreditPoint_Internal);
    }
}

float Grade_Point_Internal;
float Grade_Internal(){
    for(int i = 0; i < Num_Internal; i++){
       Grade_Point_Internal = Internal_Subject_CreditPoint[i] * Internal_percent_Arr[i];
       Arr_Grade_Point_Internal.push_back(Grade_Point_Internal);
    }
}
float SumInternal_GradePoint = 0.0;
float Sum_Of_Internal_GradePoint(){
    for(int i = 0; i < Arr_Grade_Point_Internal.size(); i++){
        SumInternal_GradePoint = SumInternal_GradePoint + Arr_Grade_Point_Internal[i];
    }
}

//Total Internal Credit Points.
float SumInternalCreditMarks = 0;
int SumOfInternalCreditMarks(){
    for(int i = 0; i < Marks_Get_Internal_Arr.size(); i++){
      SumInternalCreditMarks = SumInternalCreditMarks + Marks_Get_Internal_Arr[i]; 
    }
}

float Total_GradePoint;
float Total_CreditPoint;
float sgpa;
float Sgpa(){
    Total_GradePoint = SumInternal_GradePoint + SumExternal_GradePoint;
    Total_CreditPoint = SumInternalCreditMarks + SumExternalCreditMarks;
    sgpa = Total_GradePoint / Total_CreditPoint;
    cout<<"Your SGPA is : "<<sgpa;
    
}
int main(){
    // External Subjects
    SubjectName_External();
    MaxMarksExternal();
    MarksObtained_External();
    PercentageOfExternal();
    Credit_External();
    Grade_External();
    SumOfExternalMarks();
    SumOfExternalCreditMarks();
    Sum_Of_External_GradePoint();

    // Internal Subjects
    SubjectName_Internal();
    MaxMarksInternal();
    MarksObtained_Internal();
    PercentageOfInternal();
    Credit_Internal();
    Grade_Internal();
    SumOfInternalMarks();
    SumOfInternalCreditMarks();
    Sum_Of_Internal_GradePoint();

    // Calculate and display SGPA
    Sgpa();

    return 0;
}

