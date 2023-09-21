cout << "\n--------Login As Doctor--------\n";
        cout << "\nEnter user username: ";
        cin >> user_username;
        cout << "Enter user password: ";
        cin >> user_password;
        if (admin.doctorLogin(user_username, user_password))
        {
            cout << "\nLogin Successfully.\n"
                 << endl;
            Doctor doctorInfo = admin.getDoctorInfo(user_username);
            while (true)
            {
                cout << "1. Manage Personal Information \n2. View Total Dengue cases \n3. View Daily Dengue Cases \n4. View Dengue Alert Messages \n5. Search Status \n6. Logout \n\nEnter your choice: ";
                cin >> userMenu;

                switch (userMenu)
                {
                case 1: // Manage Personal Information
                    cout << "\n<<<<< Welcome to your profile <<<<<" << endl;
                    cout << ">>>>> User Profile >>>>>>\n";
                    cout << "Username: " << doctorInfo.getUsername() << endl;
                    cout << "Password: " << doctorInfo.getPassword() << endl;
                    cout << "Residence: " << doctorInfo.getResidence() << endl;
                    cout << "Phone Number: " << doctorInfo.getPhoneNo() << endl;

                    while (true)
                    {
                        cout << "\n >>>> Options >>>>\n";
                        cout << "\n1. Modify Username \n2. Modify Password \n3. Modify Residence \n4. Modify Phone Number \n5. Logout\n\nEnter your choice: ";

                        int modifyProfileInfo;
                        cin >> modifyProfileInfo;
                        switch (modifyProfileInfo)
                        {
                        case 1:
                            cout << "Enter new username: ";
                            cin >> newUsername;

                            admin.updateDoctorInformation(doctorInfo.getUsername(), newUsername, doctorInfo.getPassword(), doctorInfo.getResidence(), doctorInfo.getPhoneNo());
                            break;
                        case 2:
                            cout << "Enter new password: ";
                            cin >> newPassword;
                            admin.updateDoctorInformation(doctorInfo.getUsername(), doctorInfo.getUsername(), newPassword, doctorInfo.getResidence(), doctorInfo.getPhoneNo());
                            break;
                        case 3:
                            cout << "Enter new residence: ";
                            cin >> newResidence;
                            admin.updateDoctorInformation(doctorInfo.getUsername(), doctorInfo.getUsername(), doctorInfo.getPassword(), newResidence, doctorInfo.getPhoneNo());
                            break;
                        case 4:
                            cout << "Enter new phone number: ";
                            cin >> newPhoneNo;
                            admin.updateDoctorInformation(doctorInfo.getUsername(), doctorInfo.getUsername(), doctorInfo.getPassword(), doctorInfo.getResidence(), newPhoneNo);
                            break;
                        case 5:
                            return;
                        }

                        cout << "Profile information updated successfully." << endl;
                    }
                    break;

                case 2: // View Total Dengue cases
                    break;
                case 3: // View Daily Dengue Cases
                    break;
                case 4: // View Dengue Alert Messages
                    break;
                case 5: // Search Status
                    break;
                case 6: // Logout
                }
            }
        }
        else
        {
            cout << "Doctor login failed. Try again." << endl;
        }