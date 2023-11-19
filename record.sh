#! bin/bash

ch=1

while [ $ch -ne 6 ] 
	do
	
	echo "What you want to do?"
	echo -e "1)Create Book \n 2) Insert record \n 3) Display Record \n 4) Modify record \n 5) Delete record \n 6) Exit"
	
	read ch
	
	case $ch in
		1)
		touch record2.txt
		echo "File created sucessfully"
		;;
		
		2)
		echo "Enter the ID = "
		read ID
		echo "Enter the name = "
		read name
		echo "Enter the address = "
		read address
		echo "Enter the mobile number = "
		read mob
		
		n=${#mob}
		if [ $n -eq 10 ]
		then 
		echo -e $ID"\t"$name"\t"$address"\t"$mob >> record2.txt
		else 
		echo "Enter the mob number correctly"
		fi
		;;
		
		3)
		cat record2.txt
		;;
		
		4)
		echo "Enter the ID of employee want to modify = "
		read mid
		no=`grep -n $mid record2.txt | cut -c 1`
		echo $no
		echo "Enter which field you want to modify ? "
		read field
		echo "Enter the old value of $field"
		read old
		echo "Enter the new value of $field"
		read new 
		sed -i "$no s/$old/$new/" record2.txt
		;;
		
		5)
		echo "Enter ID you want to delete"
		read did
		
		sed -i '/'$did'/d' record2.txt
		;;
		
		esac
	done
