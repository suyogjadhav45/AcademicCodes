void student::Delete()
// {
//     int pos;
//     pos = search();
//     fstream f;
//     f.open("stud.dat", ios::in | ios::out | ios::binary);
//     f.seekg(0, ios::beg);
//     if (pos == 0)
//     {
//         cout << "\n\tRecord Not Found";
//         return;
//     }
//     int offset = pos * sizeof(stud);
//     f.seekp(offset);
//     rec.roll = -1;
//     strcpy(rec.name, "NULL");
//     rec.div = 'N';
//     strcpy(rec.add, "NULL");
//     f.write((char *)&rec, sizeof(stud));
//     f.seekg(0);
//     f.close();
//     cout << "\n\tRecord Deleted";
// }