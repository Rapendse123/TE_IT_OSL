create() {
  echo "Enter Address Book name:"
  read ab
  # check whether address book is available or not in current working directory
  res=$(ls | grep $ab | wc -w)

  if [ $res -gt 0 ]; then
    echo "Error: Address Book already exists"
  else
    touch $ab
    echo "Address book is created successfully"
  fi
}

display() {
  echo "Enter Address Book name:"
  read ab
  # check whether address book is available or not in current working directory
  res=$(ls | grep $ab | wc -w)

  if [ $res -gt 0 ]; then
    cat $ab
  else
    echo "Error: Address Book already exists"
  fi
}

insert() {
  echo "Enter Address Book name:"
  read ab
  # check whether address book is available or not in current working directory
  res=$(ls | grep $ab | wc -w)

  if [ $res -gt 0 ]; then
    echo "Enter email:"
    read email
    # check whether email is present in address book or not
    len=$(cat $ab | grep $email | wc -w)
    if [ $len -gt 0 ]; then
      echo "Error: Email already exists"
    else
      echo "Enter first name, last name, mobile number:"
      read fname lname mobile
      record=$(echo $fname $lname $email $mobile)
      echo $record >>$ab # append the record by using ">>"
      echo "Record inserted successfully"
    fi
  else
    echo "Error: Address Book does not exist"
  fi
}

modify() {
  echo "Enter Address Book name:"
  read ab
  # check whether address book is available or not in current working directory
  res=$(ls | grep $ab | wc -w)

  if [ $res -gt 0 ]; then
    echo "Enter email:"
    read email
    # check whether email is present in address book or not
    len=$(cat $ab | grep $email | wc -w)
    if [ $len -gt 0 ]; then
      echo "Enter modified data first name, last name, mobile"
      read fname lname mobile
      new=$(echo $fname $lname $email $mobile)
      old=$(cat $ab | grep $email)
      echo "old record: $old"
      echo "new record: $new"
      # sed stands for "search and edit"
      sed -i s/"$old"/"$new"/g $ab
      echo "record modified successfully"
    else
      echo "Error: Email does not exist"
    fi
  else
    echo "Error: Address Book does not exist"
  fi
}

delete() {
  echo "Enter Address Book name:"
  read ab
  # check whether address book is available or not in current working directory
  res=$(ls | grep $ab | wc -w)

  if [ $res -gt 0 ]; then
    echo "Enter email:"
    read email
    # check whether email is present in address book or not
    len=$(cat $ab | grep $email | wc -w)
    if [ $len -gt 0 ]; then
      old=$(cat $ab | grep $email)
      # sed stands for "search and edit"
      sed -i s/"$old"//g $ab
      sed -i /^$/d $ab
      echo "record deleted successfully"
    else
      echo "Error: Email does not exist"
    fi
  else
    echo "Error: Address Book does not exist"
  fi
}

while [ true ]; do
  echo "*****MENU*****"
  echo "1. Create Address Book"
  echo "2. Display Address Book"
  echo "3. Insert a record into Address Book"
  echo "4. Modify a record from Address Book"
  echo "5. Delete a record from Address Book"
  echo "6. Exit"

  echo "Enter choice:"
  read choice

  case $choice in
  1) create ;;
  2) display ;;
  3) insert ;;
  4) modify ;;
  5) delete ;;
  6) exit ;;
  *) echo "Wrong choice" ;;
  esac
done
