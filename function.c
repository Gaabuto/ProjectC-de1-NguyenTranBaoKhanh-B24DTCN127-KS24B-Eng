
#include "datatype.h"

void clearScreen() {
    #ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int countS = 0;
int countT = 0;


void loadStudents(Students students[],int *countS) {
    FILE *file = fopen("Student.bin", "rb");
    if (file != NULL) {
        fread(&countS, sizeof(int), 1, file);
        fread(students, sizeof(Students), *countS, file);
        fclose(file);
    }else{
    	*countS = 0;
	}
}
void saveStudents(Students students[],int countS) {
    FILE *file = fopen("Student.bin", "wb");
    if (file != NULL) {
        fwrite(&countS, sizeof(int), 1, file);
        fwrite(students, sizeof(Students), countS, file);
        fclose(file);
    }
}

void loadTeachers(Teachers teachers[], int *countT) {
    FILE *file = fopen("Teacher.bin", "rb");
    if (file != NULL) {
        fread(&countT, sizeof(int), 1, file);
        fread(teachers, sizeof(Teachers), *countT, file);
        fclose(file);
    }
}

void saveTeachers(Teachers teachers[], int countT) {
    FILE *file = fopen("Teacher.bin", "wb");
    if (file != NULL) {
        fwrite(&countT, sizeof(int), 1, file);
        fwrite(teachers, sizeof(Teachers), countT, file);
        fclose(file);
    }
}





void admin(){
	int choice;
	do{
	clearScreen();
	printf(" ***Student Management System Using C***\n\n");
	printf("\t\tMENU\n");
	printf("\t===============================\n");
	printf("\t[1] Students management.\n");
	printf("\t[2] Classrooms management.\n");
	printf("\t[3] Teacher management.\n");
	printf("\t[4] User Guideline.\n");
	printf("\t[5] About Us.\n");
	printf("\t[0] Exit the Program.\n");
	printf("\t===============================\n");
	printf("\tEnter The Choice: ");
	scanf("%d",&choice);
	getchar();
	switch(choice){
		case 1:{
			managementStudent();
			break;
		}
		case 2:{
			managementClassroom();
			break;
		}
		case 3:{
			managementTeacher();
			break;
		}
		case 4:{
			printf("chua lam @@ xin thong cam!");
			break;
		}
		case 5:{
			printf("chua lam @@ xin thong cam!");
			break;
		}
		default:{
			printf("khong hop le, moi nhap lai!\n");
			break;
		}
	}	
}while(choice != 0);
}

void managementStudent(){
	Students students[100];
	int choice;
	do{
		clearScreen();
		printf(" ***Student Management System Using C***\n\n");
		printf("\t\tStudent Menu\n");
		printf("\t===============================\n");
		printf("\t[1] Add A New Student.\n");
		printf("\t[2] Show All Student.\n");
		printf("\t[3] Search A Student.\n");
		printf("\t[4] Edit A Student.\n");
		printf("\t[5] Delete A Student.\n");
		printf("\t[6] Sort Students.\n");
		printf("\t[0] Exit the Program.\n");
		printf("\t===============================\n");
		printf("\tEnter The Choice: ");
	scanf("%d",&choice);
	getchar();
	switch(choice){
		case 1:{
			addStudents(students, &countS);
			break;
		}
		case 2:{
			showStudents(students,countS);
			break;
		}
		case 3:{
			searchStudents(students, countS);
			break;
		}
		case 4:{
			editStudents(students,countS);
			break;
		}
		case 5:{
			deleteStudents(students, &countS);
			break;
		}
		case 6:{
			sortStudents(students, countS);
			break;
		}
		case 0:{
			break;
		}
		default:{
			printf("lua chon cua ban k hop le, moi nhap lai!\n");
			break;
			}
	}
	}while (choice != 0);
}

void addStudents(Students students[],int *countS){
	clearScreen();
	int flag,flagEmail,dup,flagshort;
	printf("\t\t***Add A New Student***\n");
	
	
	
	do{
	printf("Moi ban nhap ID:");
	fgets(students[*countS].id, sizeof(students[*countS].id), stdin);
    students[*countS].id[strcspn(students[*countS].id, "\n")] = '\0';

		flag = 0;
		dup = 0;
		for(int i = 0; i < *countS; i ++){
		if(strcmp(students[*countS].id,students[i].id)== 0){
			flag = 1;
			printf("ID da bi trung, moi nhap lai!\n");
		}
	}
	if(strlen(students[*countS].id) == 0 || strspn(students[*countS].id, " ") == strlen(students[*countS].id)) {
        printf("Id cannot be empty. Please enter a valid Id.\n");
        dup = 1;
    }
	}while(flag != 0 || dup != 0);

do{
	printf("Enter The Name: ");
	fgets(students[*countS].name,sizeof(students[*countS].name),stdin);
	students[*countS].name[strcspn(students[*countS].name, "\n")] = '\0';
	flag = 0;
	dup = 0;
	if (strlen(students[*countS].name) == 0) {
        printf("Name cannot be empty. Please enter a valid name.\n");
        flag = 1;
    }
    for(int i = 0; i < *countS; i ++){
    	if(strcmp(students[*countS].name,students[i].name) == 0){
    		printf("Name already exist. Please enter a valid name.\n");
    		dup = 1;
		}
	}
	}while (flag != 0 || dup != 0);

do{
	printf("Enter The Email: ");
    fgets(students[*countS].Email, sizeof(students[*countS].Email), stdin);
    students[*countS].Email[strcspn(students[*countS].Email, "\n")] = '\0';
    flag = 0;
	dup = 0;
	flagEmail = 0;
    if (strlen(students[*countS].Email) == 0 || strspn(students[*countS].Email, " ") == strlen(students[*countS].Email)) {
        printf("Email cannot be empty. Please enter a valid email.\n");
        flag = 1;
    }
    if (strchr(students[*countS].Email,'@') == NULL){
    	printf("dinh dang email k hop le\n");
    	flagEmail = 1;
 }
    for(int i = 0; i < *countS; i ++){
    	if(strcmp(students[*countS].Email,students[i].Email) == 0){
    		printf("Email already exist. Please enter a valid email.\n");
    		dup = 1;
		}
	}  
} while (flag != 0 || dup != 0 || flagEmail != 0);

do{
	printf("Enter The Phone: ");
    fgets(students[*countS].Phone, sizeof(students[*countS].Phone), stdin);
    students[*countS].Phone[strcspn(students[*countS].Phone, "\n")] = '\0';
	flag = 0;
	dup = 0;
	flagshort = 0;
    if (strlen(students[*countS].Phone) == 0) {
        printf("Phone cannot be empty. Please enter a valid phone number.\n");
        flag = 1;
    }
    
    for(int i = 0; i < *countS; i++) {
        if(strcmp(students[*countS].Phone, students[i].Phone) == 0) {
            printf("Phone already exists. Please enter a valid phone number.\n");
            dup = 1;
        }
    }
     if (strlen(students[*countS].Phone) < 10 || strspn(students[*countS].Phone, "0123456789") != strlen(students[*countS].Phone)) {
        printf("Phone number must have at least 10 digits and only contain numbers.\n");
        flagshort = 1;
    }
} while (flag != 0 || dup != 0|| flagshort != 0);
	
	
	
do{
	printf("Enter the Number of Courses: ");
    scanf("%d", &students[*countS].numCourse);
    getchar();
	if (students[*countS].numCourse < 1 || students[*countS].numCourse > 100) {
    printf("So khoa hoc khong hop le, moi ban nhap lai!");	
    }
	}while(students[*countS].numCourse < 1 || students[*countS].numCourse > 100);
        
    
    for (int i = 0; i < students[*countS].numCourse; i++) {
    do {
        printf("Enter Course %d Name: ", i + 1);
    	fgets(students[i].course,sizeof(students[i].course),stdin);
        students[i].course[strcspn(students[i].course, "\n")] = '\0';

        if (strlen(students[i].course) == 0) {
            printf("Ten mon hoc khong hop le, moi ban nhap lai!\n");
        }
    } while (strlen(students[i].course) == 0);
}

(*countS)++;
saveStudents(students, countS);
printf("\nAdd student complete!\nBam enter de ve home");
getchar();
return; 	

}

void showStudents(Students students[],int countS){
	clearScreen();
	loadStudents(students, &countS);
	char answer;
	printf("**** ALL Students ****\n");
	printf("| ID | Name     | Email                    | Phone        | NO.Course |\n");
	printf("|----|----------|--------------------------|--------------|-----------|\n");
	
	for(int i = 0; i < countS; i ++){
		printf("|%-4s| %-8s | %-23s | %-12s | %-9d |\n",
             students[i].id, students[i].name, students[i].Email, students[i].Phone, students[i].numCourse);
    printf("|----|----------|--------------------------|--------------|-----------|\n");
}
do{
    	printf("\nGo back(b)? or Exit(0)?: ");
    	scanf(" %c", &answer);
    if( answer == 'b'){
    	return ;
	}else if(answer == '0'){
		exit (0);
	}else{
		printf("k hop le, moi nhap lai!\n");
	}
	}while ( answer != 'b' && answer != '0' );
}

void searchStudents(Students students[], int countS){
	loadStudents(students, &countS);
	char findName[20];
	int key,flag = 0;
	clearScreen();
	if(countS == 0){
		printf("khong co gi trong danh sach! moi ban nhap hoc sinh vao danh sach da\nBam nut Enter de quay lai: ");
		getchar();
		return;
	}
	
	printf("Moi ban nhap ten sinh vien can tim: ");
	fgets(findName,sizeof(findName),stdin);
	findName[strcspn(findName,"\n")] = '\0';
	for ( int i = 0; i < countS; i ++){
		if(strstr(students[i].name,findName) != NULL){
			flag ++;
			printf("Da tim thay hoc sinh:\n");
		printf("| ID | Name     | Email                    | Phone        | NO.Course |\n");
		printf("|----|----------|--------------------------|--------------|-----------|\n");
		printf("| %s  | %-8s | %-23s  | %-12s | %d         |\n",
			students[i].id, 
            students[i].name, 
            students[i].Email, 
            students[i].Phone, 
            students[i].numCourse);
        printf("|----|----------|--------------------------|--------------|-----------|\n");
		}
	}
	if(flag == 0){
		printf("Khong co hoc sinh nay trong danh sach!\nBam nut bat ky de quay lai: ");
		getchar();
		return;
	}else{
            printf("Bam nut enter de quay lai: ");
            getchar();
            return;
	}
}

void editStudents(Students students[], int *countS){
	loadStudents(students, &countS);
	clearScreen();
	char findID[10], newName[20],newEmail[30],newPhone[20],newCourse[20];
	int flag = 0,edit = -1,newNumCourse;
	if(countS == 0){
		printf("khong co gi trong danh sach! moi ban nhap hoc sinh vao danh sach da\nBam nut Enter de quay lai: ");
		getchar();
		return;
	}
	printf("Moi nhap ID sinh vien ban muon sua: ");
	fgets(findID,sizeof(findID),stdin);
	findID[strcspn(findID,"\n")] = '\0';
	for (int i = 0; i < *countS; i ++){
		if(strcmp(findID,students[i].id) == 0){
			flag++;
			edit = i;
    }
}
        if (flag == 0){
			printf("ID sinh vien khong ton tai!!");
			printf("nhan nut enter de quay lai!");
        getchar();
        return;
		}else{
			printf("Thong tin sinh vien:\n");
			printf("| ID | Name     | Email                    | Phone        | NO.Course |\n");
		printf("|----|----------|--------------------------|--------------|-----------|\n");
		printf("| %s  | %-8s | %-23s  | %-12s | %d         |\n",
			students[edit].id, 
            students[edit].name, 
            students[edit].Email, 
            students[edit].Phone, 
            students[edit].numCourse);
        printf("|----|----------|--------------------------|--------------|-----------|\n");
        printf("Moi ban nhap du lieu moi! Neu khong thay doi thi bam enter!\n");
        printf("Moi ban nhap ten moi: ");
        fgets(newName,sizeof(newName),stdin);
        if(newName[0] != '\n'){
            newName[strcspn(newName,"\n")] = '\0';
            strcpy(students[edit].name, newName);
		}
		printf("Moi ban nhap Email moi: ");
		fgets(newEmail,sizeof(newEmail),stdin);
		newEmail[strcspn(newEmail, "\n")] = '\0'; 
        strcpy(students[edit].Email, newEmail);
        
        printf("Moi ban nhap sdt moi: ");
        fgets(newPhone, sizeof(newPhone), stdin);
        if (newPhone[0] != '\n') {
            newPhone[strcspn(newPhone, "\n")] = '\0';
            strcpy(students[edit].Phone, newPhone);
		}
		printf("Moi ban nhap so mon hoc( nhap -1 neu muon giu nguyen): ");
		scanf("%d",&newNumCourse);
		getchar();
		if(newNumCourse != -1){
			students[edit].numCourse = newNumCourse;
			for(int i = 0; i < newNumCourse;i++){
			printf("Moi ban nhap mon hoc thu %d: ",i+1);
			fgets(students[edit].course[i], sizeof(students[edit].course[i]), stdin);
		}
		
		}
		saveStudents(students, countS);
        printf("Chinh sua thanh cong !\nBam nut enter de ve trang chu");
        getchar();
        return;
	}
}

void deleteStudents(Students students[], int *countS){
	clearScreen();
	char deleteID[10];
	int flag = 0;
	if(countS == 0){
		printf("khong co gi trong danh sach! moi ban nhap hoc sinh vao danh sach da\nBam nut Enter de quay lai: ");
		getchar();
		return;
	}
	printf("Moi ban nhap id can xoa:");
	fgets(deleteID,sizeof(deleteID),stdin);
	deleteID[strcspn(deleteID,"\n")] = '\0';
	for ( int i = 0; i < *countS; i ++){
		if( strcmp(students[i].id, deleteID) == 0){
		flag ++;
		for (int j = i;j < *countS - 1; j ++){
			students[j] = students[j + 1];
		}	
		(*countS)--;
		saveStudents(students, countS);
		break;
	}
	}

	if ( flag == 0){
		printf("K tim thay id sinh vien\n");
		printf("Bam enter de ve menu!");
		getchar();
		return;
	}

    printf("Xoa sinh vien thanh cong\n");
    printf("Moi ban bam enter de ve menu");
    getchar();
    return;
}

void sortStudents(Students students[], int countS){
	clearScreen();
	loadStudents(students, &countS);
	char ans;
	Students temp;
if(countS == 0){
		printf("khong co gi trong danh sach! moi ban nhap hoc sinh vao danh sach da\nBam nut Enter de quay lai: ");
		getchar();
		return;
	}

    printf("\nMoi ban chon cach sap xep(theo ten):\na) Tang dan\nb) Giam dan\nLua chon cua ban: ");
    scanf(" %c", &ans);
    if (ans != 'a' && ans != 'b') {
        printf("Invalid choice! Press Enter to return.\n");
        getchar();
        return;
    }

    for (int i = 0; i < countS - 1; i++) {
        for (int j = 0; j < countS - i - 1; j++) {
            if ((ans == 'a' && strcmp(students[j].name, students[j + 1].name) > 0) || 
                (ans == 'b' && strcmp(students[j].name, students[j + 1].name) < 0)) {
                Students temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
		printf("\nDanh sach sau khi sap xep:\n");
        printf("| ID   | Name          | Email                  | Phone       | NO.Course |\n");
        printf("|------|---------------|------------------------|-------------|-----------|\n");
        for (int i = 0; i < countS; i++) {
            printf("| %-4s | %-13s | %-22s | %-11s | %-9d |\n",
                   students[i].id, students[i].name, students[i].Email, students[i].Phone, students[i].numCourse);
            printf("|------|---------------|------------------------|-------------|-----------|\n");
        }
	printf("Luu thanh cong, an enter de ve trang truoc.\n");
	while (getchar() != '\n');
	getchar();
}



void managementTeacher(){
	Teachers teachers[100];
	int choice;
	do{
		clearScreen();
		printf(" ***Teacher Management System Using C***\n\n");
		printf("\t\tTeacher Menu\n");
		printf("\t===============================\n");
		printf("\t[1] Add A New Teacher.\n");
		printf("\t[2] Show All Teacher.\n");
		printf("\t[3] Search A Teacher.\n");
		printf("\t[4] Edit A Teacher.\n");
		printf("\t[5] Delete A Teacher.\n");
		printf("\t[6] Sort Teachers.\n");
		printf("\t[0] Exit the Program.\n");
		printf("\t===============================\n");
		printf("\tEnter The Choice: ");
	scanf("%d",&choice);
	getchar();
	switch(choice){
		case 1:{
			addTeachers(teachers, &countT);
			break;
		}
		case 2:{
			showTeachers(teachers,countT);
			break;
		}
		case 3:{
			searchTeachers(teachers, countT);
			break;
		}
		case 4:{
			editTeachers(teachers,&countT);
			break;
		}
		case 5:{
			deleteTeachers(teachers, &countT);
			break;
		}
		case 6:{
			sortTeachers(teachers, countT);
			break;
		}
		case 0:{
			break;
		}
		default:{
			printf("lua chon cua ban k hop le, moi nhap lai!\n");
			break;
			}
	}
	}while (choice != 0);
}

void addTeachers(Teachers teachers[],int *countT){
	clearScreen();
	int flag,flagEmail,dup,flagshort;
	printf("\t\t***Add A New Teacher***\n");
	
	
	
do{
	printf("Moi ban nhap ID:");
	fgets(teachers[*countT].id, sizeof(teachers[*countT].id), stdin);
    teachers[*countT].id[strcspn(teachers[*countT].id, "\n")] = '\0';

		flag = 0;
		dup = 0;
		for(int i = 0; i < *countT; i ++){
		if(strcmp(teachers[*countT].id,teachers[i].id)== 0){
			flag = 1;
			printf("ID da bi trung, moi nhap lai!\n");
		}
	}
	if(strlen(teachers[*countT].id) == 0 || strspn(teachers[*countT].id, " ") == strlen(teachers[*countT].id)) {
        printf("Id cannot be empty. Please enter a valid Id.\n");
        dup = 1;
    }
	}while(flag != 0 || dup != 0);

do{
	printf("Enter The Name: ");
	fgets(teachers[*countT].name,sizeof(teachers[*countT].name),stdin);
	teachers[*countT].name[strcspn(teachers[*countT].name, "\n")] = '\0';
	flag = 0;
	dup = 0;
	if (strlen(teachers[*countT].name) == 0) {
        printf("Name cannot be empty. Please enter a valid name.\n");
        flag = 1;
    }
    for(int i = 0; i < *countT; i ++){
    	if(strcmp(teachers[*countT].name,teachers[i].name) == 0){
    		printf("Name already exist. Please enter a valid name.\n");
    		dup = 1;
		}
	}
	}while (flag != 0 || dup != 0);

do{
	printf("Enter The Email: ");
    fgets(teachers[*countT].Email, sizeof(teachers[*countT].Email), stdin);
    teachers[*countT].Email[strcspn(teachers[*countT].Email, "\n")] = '\0';
    flag = 0;
	dup = 0;
	flagEmail = 0;
    if (strlen(teachers[*countT].Email) == 0 || strspn(teachers[*countT].Email, " ") == strlen(teachers[*countT].Email)) {
        printf("Email cannot be empty. Please enter a valid email.\n");
        flag = 1;
    }
    if (strchr(teachers[*countT].Email,'@') == NULL){
    	printf("dinh dang email k hop le\n");
    	flagEmail = 1;
 }
    for(int i = 0; i < *countT; i ++){
    	if(strcmp(teachers[*countT].Email,teachers[i].Email) == 0){
    		printf("Email already exist. Please enter a valid email.\n");
    		dup = 1;
		}
	}  
} while (flag != 0 || dup != 0 || flagEmail != 0);

do{
	printf("Enter The Phone: ");
    fgets(teachers[*countT].Phone, sizeof(teachers[*countT].Phone), stdin);
    teachers[*countT].Phone[strcspn(teachers[*countT].Phone, "\n")] = '\0';
	flag = 0;
	dup = 0;
	flagshort = 0;
    if (strlen(teachers[*countT].Phone) == 0) {
        printf("Phone cannot be empty. Please enter a valid phone number.\n");
        flag = 1;
    }
    
    for(int i = 0; i < *countT; i++) {
        if(strcmp(teachers[*countT].Phone, teachers[i].Phone) == 0) {
            printf("Phone already exists. Please enter a valid phone number.\n");
            dup = 1;
        }
    }
     if (strlen(teachers[*countT].Phone) < 10 || strspn(teachers[*countT].Phone, "0123456789") != strlen(teachers[*countT].Phone)) {
        printf("Phone number must have at least 10 digits and only contain numbers.\n");
        flagshort = 1;
    }
} while (flag != 0 || dup != 0|| flagshort != 0);


(*countT)++;
saveTeachers(teachers, countT);
printf("\nAdd teacher complete!\nBam enter de ve home");
getchar();
return; 	

}

void showTeachers(Teachers teachers[], int countT) {
    clearScreen();
    loadTeachers(teachers,&countT);
    char answer;
    printf("**** ALL Teachers ****\n");
    printf("| ID | Name     | Email                    | Phone        |\n");
    printf("|----|----------|--------------------------|--------------|\n");

    for (int i = 0; i < countT; i++) {
        printf("|%-4s| %-8s | %-23s | %-12s |\n",
               teachers[i].id, teachers[i].name, teachers[i].Email, teachers[i].Phone);
        printf("|----|----------|--------------------------|--------------|\n");
    }
    do {
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf(" %c", &answer);
        if (answer == 'b') {
            return;
        } else if (answer == '0') {
            exit(0);
        } else {
            printf("Khong hop le, moi nhap lai!\n");
        }
    } while (answer != 'b' && answer != '0');
}

void searchTeachers(Teachers teachers[], int countT) {
    char findName[20];
    int flag = 0;
    clearScreen();
    loadTeachers(teachers,&countT);
    if (countT == 0) {
        printf("Khong co gi trong danh sach! Moi ban nhap giao vien vao danh sach da.\nBam nut Enter de quay lai: ");
        getchar();
        return;
    }
    printf("Moi ban nhap ten giao vien can tim: ");
    fgets(findName, sizeof(findName), stdin);
    findName[strcspn(findName, "\n")] = '\0';
    for (int i = 0; i < countT; i++) {
        if (strstr(teachers[i].name, findName) != NULL) {
            flag++;
            printf("Da tim thay giao vien:\n");
            printf("| ID | Name     | Email                    | Phone        |\n");
            printf("|----|----------|--------------------------|--------------|\n");
            printf("| %s  | %-8s | %-23s  | %-12s |\n",
                   teachers[i].id, teachers[i].name, teachers[i].Email, teachers[i].Phone);
            printf("|----|----------|--------------------------|--------------|\n");
        }
    }
    if (flag == 0) {
        printf("Khong co giao vien nay trong danh sach!\nBam nut bat ky de quay lai: ");
        getchar();
        return;
    } else {
        printf("Bam nut Enter de quay lai: ");
        getchar();
        return;
    }
}

void editTeachers(Teachers teachers[], int *countT){
	clearScreen();
	loadTeachers(teachers,&countT);
	if(countT == 0){
		printf("khong co gi trong danh sach! moi ban nhap hoc sinh vao danh sach da\nBam nut Enter de quay lai: ");
		getchar();
		return;
	}
	char findID[10], newName[20],newEmail[30],newPhone[20];
	int flag = 0,edit = -1;
	printf("Moi nhap ID giao vien ban muon sua: ");
	fgets(findID,sizeof(findID),stdin);
	findID[strcspn(findID,"\n")] = '\0';
	for (int i = 0; i < *countT; i ++){
		if(strcmp(findID,teachers[i].id) == 0){
			flag++;
			edit = i;
    }
}
        if (flag == 0){
			printf("ID giao vien khong ton tai!!");
			printf("nhan nut enter de quay lai!");
        getchar();
        return;
		}else{
			printf("Thong tin giao vien:\n");
			printf("| ID | Name     | Email                    | Phone        |\n");
		printf("|----|----------|--------------------------|--------------|\n");
		printf("| %s  | %-8s | %-23s  | %-12s | %d         |\n",
			teachers[edit].id, 
            teachers[edit].name, 
            teachers[edit].Email, 
            teachers[edit].Phone
			);
        printf("|----|----------|--------------------------|--------------|\n");
        printf("Moi ban nhap du lieu moi! Neu khong thay doi thi bam enter!\n");
        printf("Moi ban nhap ten moi: ");
        fgets(newName,sizeof(newName),stdin);
        if(newName[0] != '\n'){
            newName[strcspn(newName,"\n")] = '\0';
            strcpy(teachers[edit].name, newName);
		}
		printf("Moi ban nhap Email moi: ");
		fgets(newEmail,sizeof(newEmail),stdin);
		newEmail[strcspn(newEmail, "\n")] = '\0'; 
        strcpy(teachers[edit].Email, newEmail);
        
        printf("Moi ban nhap sdt moi: ");
        fgets(newPhone, sizeof(newPhone), stdin);
        if (newPhone[0] != '\n') {
            newPhone[strcspn(newPhone, "\n")] = '\0';
            strcpy(teachers[edit].Phone, newPhone);
		}
		}
		saveTeachers(teachers, countT);
        printf("Chinh sua thanh cong !\nBam nut enter de ve trang chu");
        getchar();
        return;
	}

void deleteTeachers(Teachers teachers[], int *countT){
	clearScreen();
	char deleteID[10];
	int flag = 0;
	if(countT == 0){
		printf("khong co gi trong danh sach! moi ban nhap hoc sinh vao danh sach da\nBam nut Enter de quay lai: ");
		getchar();
		return;
	}
	printf("Moi ban nhap id can xoa:");
	fgets(deleteID,sizeof(deleteID),stdin);
	deleteID[strcspn(deleteID,"\n")] = '\0';
	for ( int i = 0; i < *countT; i ++){
		if( strcmp(teachers[i].id, deleteID) == 0){
		flag ++;
		for (int j = i;j < *countT - 1; j ++){
			teachers[j] = teachers[j + 1];
		}	
		(*countT)--;
		saveTeachers(teachers, countT);
		break;
	}
	}

	if ( flag == 0){
		printf("K tim thay id giao vien\n");
		printf("Bam enter de ve menu!");
		getchar();
		return;
	}

    printf("Xoa giao vien thanh cong\n");
    printf("Moi ban bam enter de ve menu");
    getchar();
    return;
}

void sortTeachers(Teachers teachers[], int countT){
	clearScreen();
	loadTeachers(teachers,&countT);
	char ans;
	Teachers clone;
	if(countT == 0){
		printf("khong co gi trong danh sach! moi ban nhap hoc sinh vao danh sach da\nBam nut Enter de quay lai: ");
		getchar();
		return;
	}

    printf("\nMoi ban chon cach sap xep(theo ten):\na) Tang dan\nb) Giam dan\nLua chon cua ban: ");
    scanf(" %c", &ans);
    if (ans != 'a' && ans != 'b') {
        printf("Invalid choice! Press Enter to return.\n");
        getchar();
        return;
    }

    for (int i = 0; i < countT - 1; i++) {
        for (int j = 0; j < countT - i - 1; j++) {
            if ((ans == 'a' && strcmp(teachers[j].name, teachers[j + 1].name) > 0) || 
                (ans == 'b' && strcmp(teachers[j].name, teachers[j + 1].name) < 0)) {
                Teachers temp = teachers[j];
                teachers[j] = teachers[j + 1];
                teachers[j + 1] = temp;
            }
        }
    }
		printf("\nDanh sach sau khi sap xep:\n");
        printf("| ID   | Name          | Email                  | Phone       |\n");
        printf("|------|---------------|------------------------ |-------------|\n");
        for (int i = 0; i < countT; i++) {
            printf("| %-4s | %-13s | %-22s | %-11s | %-9d |\n",
                   teachers[i].id, teachers[i].name, teachers[i].Email, teachers[i].Phone);
            printf("|------|---------------|------------------------ |-------------|\n");
        }
	printf("Luu thanh cong, an enter de ve trang truoc.\n");
	while (getchar() != '\n');
	getchar();
}




void managementClassroom(){
	clearScreen();
	int choice;
	Classroom classroom[100];
printf(" ***Classroom Management System Using C***\n\n");
printf("\t\tClassroom Menu\n");
printf("\t===============================\n");
printf("\t[1] Add A New Classroom.\n");
printf("\t[2] Show All Classrooms.\n");
printf("\t[3] Search A Classroom.\n");
printf("\t[4] Edit A Classroom.\n");
printf("\t[5] Delete A Classroom.\n");
printf("\t[6] Sort Classrooms.\n");
printf("\t[0] Exit the Program.\n");
printf("\t===============================\n");
printf("\tEnter The Choice: ");
scanf("%d",&choice);
	getchar();
	switch(choice){
		case 1:{
			addClassroom(classroom);
			break;
		}
		case 2:{
			showClassroom(classroom);
			break;
		}
		case 3:{
			detailClassroom(classroom);
			break;
		}
		case 4:{
			editClassroom(classroom);
			break;
		}
		case 5:{
			deleteClassroom(classroom);
			break;
		}
		case 6:{
			sortClassroom(classroom);
			break;
		}
		case 7:{
			addstudentinclass(classroom);
			break;
		}
		case 8:{
			deletestudentinclass(classroom);
			break;
		}
		case 0:{
			break;
		}
		default:{
			printf("lua chon cua ban k hop le, moi nhap lai!\n");
			break;
		}
	}
}

void addClassroom(Classroom classroom[]){
	clearScreen();
	printf("Moi nhap thong tin lop: ");
	getchar();
}

void showClassroom(Classroom classroom[]){
	clearScreen();
	printf("e chua lam @@");
	getchar();
}

void detailClassroom(Classroom classroom[]){
	clearScreen();
	printf("Moi ban nhap Id lop muon xem: ");
	getchar();
}
void editClassroom(Classroom classroom[]){
	clearScreen();
	printf("Moi ban nhap Id lop muon sua: ");
	getchar();
}
void deleteClassroom(Classroom classroom[]){
	clearScreen();
	printf("Moi nhap Id lop muon xoa: ");
	getchar();
}
void sortClassroom(Classroom classroom[]){
	clearScreen();
	printf("ban muon chon sap xep nhu the nao\na) tu id thap len cao\nb) tu id cao xuong thap");
	getchar();
}

void addstudentinclass(Classroom classroom[]){
	clearScreen();
	printf("Moi ban nhap id sinh vien muon them vao lop: ");
	getchar();
}
void deletestudentinclass(Classroom classroom[]){
	clearScreen();
	printf("Moi ban nhap id sinh vien muon xoa khoi lop: ");
	getchar();
}
