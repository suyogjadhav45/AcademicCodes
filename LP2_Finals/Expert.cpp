#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a structure to represent a patient
struct Patient
{
    string name;
    int age;
    string gender;
    string symptoms;
};

// Function to recommend a medical facility based on patient symptoms
string recommendMedicalFacility(const Patient &patient)
{
    if (patient.symptoms == "Fever" || patient.symptoms == "Cough" || patient.symptoms == "Sore throat")
    {
        if (patient.age >= 60)
        {
            return "Recommendation: Visit a specialized geriatric hospital.";
        }
        else
        {
            return "Recommendation: Visit a general hospital.";
        }
    }
    else if (patient.symptoms == "Chest pain" || patient.symptoms == "Shortness of breath")
    {
        return "Recommendation: Go to the nearest emergency room immediately!";
    }
    else if (patient.symptoms == "Broken bone" || patient.symptoms == "Sprain")
    {
        return "Recommendation: Visit an orthopedic clinic or urgent care center.";
    }
    else if (patient.symptoms == "Headache" || patient.symptoms == "Migraine")
    {
        return "Recommendation: Consult a neurologist.";
    }
    else
    {
        return "No recommendation available for the given symptoms.";
    }
}

int main()
{
    // Ask for patient information
    Patient patient;
    cout << "Hospitals and Medical Facilities" << endl;
    cout << "------------------------------" << endl;
    cout << "Enter patient name: ";
    getline(cin, patient.name);
    cout << "Enter patient age: ";
    cin >> patient.age;
    cout << "Enter patient gender: ";
    cin >> patient.gender;
    cin.ignore(); // Ignore the newline character in the input buffer
    cout << "Enter patient symptoms: ";
    getline(cin, patient.symptoms);

    // Get the recommendation based on patient symptoms
    string recommendation = recommendMedicalFacility(patient);

    // Display the recommendation
    cout << endl;
    cout << "Recommendation" << endl;
    cout << "--------------" << endl;
    cout << recommendation << endl;

    return 0;
}