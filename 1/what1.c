// Name : Anubhav Dinesh Patel
// Roll No : 20
// Reg No : 218
void what(int data[], int no) {
    int i = 1;
    while (i < no) {
        int temp = data[i];
        int j = i - 1;
        while (j >= 0) {
            if (data[j] < temp) {
                data[j+1] = data[j];
                j--;
            }
            else { 
                break;
            }
        }
        data[j+1] = temp;
        i++;
    }
}