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

float AA = 10.0, A = 9.0, B = 8.0, C = 7.0, D = 6.0, P = 5.0, F = 0.0;

int Num_External, Num_Internal, Sub; 
string Subject_External;

//Storing Grade point like : AA = 10, A = 9, B = 8, C = 7, D = 6, P = 5, F = 0;
vector<float>External_percent_Arr;
vector<float>Internal_percent_Arr;

//Storing Grade Marks to give their corresponding point like A+, A, B, C, D, P, F;
vector<float>Arr_Grade_Point_External;
vector<float>Arr_Grade_Point_Internal;

//Array for Subject Name and Subject of External and Internal.
vector<string> Arr_Subject_Name_External;
vector<string> Arr_Subject_Name_Internal;

//Marks you Supposing to Get in External and Internal.
vector<float> Marks_Get_External_Arr;
vector<float> Marks_Get_Internal_Arr;
vector<float> Max_Marks_External_Arr;
vector<float> Max_Marks_Internal_Arr;

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

//Taking Input of Maximum Marks For which exam is conducted E.g,: Full Marks = 10.
float Maximum_External_Marks;
void MaxMarksExternal(){
    for(int i = 0; i < Num_External; i++){
        cout<<"Enter Maximum Marks for which Exam is conducted for "<<Arr_Subject_Name_External[i]<<" : "; 
        cin>>Maximum_External_Marks;
        Max_Marks_External_Arr.push_back(Maximum_External_Marks);
    }
}

//External Marks Suppose You Get Out of Maximum Marks Like in 100 you score 80.
void MarksObtained_External(){
    for(int i = 0; i < Num_External; i++){
        cout<<"Enter Your Subject Marks You're expecting "<<Arr_Subject_Name_External[i]<<" : ";
        cin>>Sub;
        Marks_Get_External_Arr.push_back(Sub);
    }
}

//Give Grade AA, A , B, C, D, P, F and Storing in External_percent_Arr;
float Percent_External;
void PercentageOfExternal(){
    for(int i = 0; i < Num_External; i++){
       Percent_External = (double) (Marks_Get_External_Arr[i] / Max_Marks_External_Arr[i])*100;
       if(Percent_External >= 90.0) External_percent_Arr.push_back(AA);
       else if(Percent_External >= 80.0 && Percent_External < 90.0) External_percent_Arr.push_back(A);
       else if(Percent_External >= 70.0 && Percent_External < 80.0) External_percent_Arr.push_back(B);
       else if(Percent_External >= 60.0 && Percent_External < 70.0) External_percent_Arr.push_back(C);
       else if(Percent_External >= 50.0 && Percent_External < 60.0) External_percent_Arr.push_back(D);
       else if(Percent_External >= 35.0 && Percent_External < 50.0) External_percent_Arr.push_back(P);
       else External_percent_Arr.push_back(F);
    }
}

//External Credit Input.
float CreditPoint_External;
void Credit_External(){
    for(int i = 0; i < Num_External; i++){
        cout<<"Enter the Credit points of  "<<Arr_Subject_Name_External[i]<<": ";
        cin>>CreditPoint_External;
        External_Subject_CreditPoint.push_back(CreditPoint_External);
    }
}
//Adding External Credit Points.
float SumExternalCreditPoints = 0;
void SumOfExternalCreditMarks(){
    for(int i = 0; i < Marks_Get_External_Arr.size(); i++){
      SumExternalCreditPoints += External_Subject_CreditPoint[i]; 
    }
}

//Sending Grade marks to Arr_Grade_Points_External
float Grade_Point_External;
void Grade_External(){
    for(int i = 0; i < Num_External; i++){
       Grade_Point_External = External_Subject_CreditPoint[i] * External_percent_Arr[i];
       Arr_Grade_Point_External.push_back(Grade_Point_External);
    }
}

//Adding Sum of Arr Grade marks From Arr_Grade_Points_External.
float SumExternal_GradePoint = 0.0;
void Sum_Of_External_GradePoint(){
    for(int i = 0; i < Arr_Grade_Point_External.size(); i++){
        SumExternal_GradePoint += Arr_Grade_Point_External[i];
    }
}

//Taking input of Internal or Practical No of Subject and storing in Arr_Subject_Name_Internal.
string Subject_Internal;
void SubjectName_Internal(){
    cout<<"Enter How many Subject you have in Your Internal Or Viva : ";
    cin>>Num_Internal;
    for(int i = 0; i < Num_Internal; i++){
        cout<<"Enter "<<i+1<<" Subjects names : ";
        cin>>Subject_Internal;
        Arr_Subject_Name_Internal.push_back(Subject_Internal);
    }
}

//Input of Internal Marks for which exam is conducted or full Marks like out of 100.
float Maximum_Internal_Marks;
void MaxMarksInternal(){
    for(int i = 0; i < Num_Internal; i++){
       cout<<"Enter Maximum Marks for which Exam is conducted :  "<<Arr_Subject_Name_Internal[i]<<" : "; 
       cin>>Maximum_Internal_Marks;
       Max_Marks_Internal_Arr.push_back(Maximum_Internal_Marks);
    }
}

//Internal Marks You Expected to get like 50 out of 100 or like 40 out of 50.
void MarksObtained_Internal(){
    for(int i = 0; i < Num_Internal; i++){
        cout<<"Enter Your Subject Marks You're expecting "<<Arr_Subject_Name_Internal[i]<<" : ";
        cin>>Sub;
        Marks_Get_Internal_Arr.push_back(Sub);
    }
}

//Give Grade AA, A , B, C, D, P, F and Storing in Internal_percent_Arr;
float Percent_Internal;
void PercentageOfInternal(){
    for(int i = 0; i < Num_Internal; i++){
       Percent_Internal = (Marks_Get_Internal_Arr[i] / Max_Marks_Internal_Arr[i])*100;
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
float CreditPoint_Internal;
void Credit_Internal(){
    for(int i = 0; i < Num_Internal; i++){
        cout<<"Enter the Credit points of Enternal Subjects "<<Arr_Subject_Name_Internal[i]<<": ";
        cin>>CreditPoint_Internal;
        Internal_Subject_CreditPoint.push_back(CreditPoint_Internal);
    }
}

// Storing Grade Marks which is multiple of grade points * Credit points.
float Grade_Point_Internal;
void Grade_Internal(){
    for(int i = 0; i < Num_Internal; i++){
       Grade_Point_Internal = Internal_Subject_CreditPoint[i] * Internal_percent_Arr[i];
       Arr_Grade_Point_Internal.push_back(Grade_Point_Internal);
    }
}

//Adding Grade Marks.
float SumInternal_GradePoint = 0.0;
void Sum_Of_Internal_GradePoint(){
    for(int i = 0; i < Arr_Grade_Point_Internal.size(); i++){
        SumInternal_GradePoint += Arr_Grade_Point_Internal[i];
    }
}

//Adding Internal Credit Points.
float SumInternalCreditPoints = 0;
void SumOfInternalCreditMarks(){
    
    for(int i = 0; i < Internal_Subject_CreditPoint.size(); i++){
      SumInternalCreditPoints += Internal_Subject_CreditPoint[i]; 
    }
}

//Calculating Total Grade_Points by Adding SumInternal_Gradepoints and SumExternal Grade Point.
//Calculating Total Credit_Points by Adding SumInternal_CreditPoints and SumExternal_CreditPoints.
//Then Calculating SGPA ANd Rounding off.
float Total_GradePoint;
float Total_CreditPoint;
float sgpa;
void Sgpa(){
    Total_GradePoint = SumInternal_GradePoint + SumExternal_GradePoint;
    Total_CreditPoint = SumInternalCreditPoints + SumExternalCreditPoints;
    sgpa = Total_GradePoint / Total_CreditPoint;
    sgpa = round(sgpa*100)/100;
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
    // SumOfExternalMarks();
    SumOfExternalCreditMarks();
    Sum_Of_External_GradePoint();

    // Internal Subjects
    SubjectName_Internal();
    MaxMarksInternal();
    MarksObtained_Internal();
    PercentageOfInternal();
    Credit_Internal();
    Grade_Internal();
    SumOfInternalCreditMarks();
    Sum_Of_Internal_GradePoint();

    Sgpa();

    return 0;
}

