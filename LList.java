public class LList {
  
  //Name: Danny Nsouli

  public LNode head;
  /* You may not add more data members to this class. */
  
  public void printList(){
    LNode entry = head;
    System.out.println("List Contents:");
    while (entry != null) {
      System.out.printf("  %s is at %f, %f\n", entry.name, entry.latitude, entry.longitude);
      entry = entry.next;
    }
  }

  public int addNode(String name, double lat, double lon){
    
     LNode newNode = new LNode(name,lat,lon);
     //System.out.println(newNode.name);
    if (head == null) {
       // System.out.println(1);          //if head is null then its an empty list so place new node at head
        head = newNode; 
        return 0;
    } 
    else {
        LNode cNode = head;
        int counter = 1;
     // System.out.println(2);
        while (cNode.next != null) {        //otherwise go through the list until the next node after the current is null
                                            //when loop stops means you have reached the end where the newNode will be placed
            cNode = cNode.next;
            counter++;
        }
        cNode.next = newNode;
      return counter;
    }
     
  }
  
  
  public int remNode(String name){
    if (head == null) {
        System.out.println("Error, empty list!");   //if head is null then its an empty list meaning there is nothing to remove
        return -1;
    }
   if(head.name.equals(name)){
      head=head.next;             //if the head has the targeted name then it must be removed
      return 0;
    }
    else {
        LNode cNode = head;
        int counter = 1;
        while (cNode.next != null) {
            if(cNode.next.name.equals(name)){
            cNode.next= cNode.next.next;              //otherwise the loop will traverse the list until it gets to the end
                                                      //checking each node's name for the targeted name with the equals string function
            //cNode.next.next=null;                    //which ever node has the same name will be removed
            
            System.out.println("Counter: "+counter);
            return counter;
              
            }
          
          counter++;
          cNode = cNode.next;
        }
      System.out.print("Error!! Name not found in list");  //if the name is not found in the list then nothing is removed
      return -1;
      
    }
  }

  //if head is lower in longitude case
  public int addSortedNode(String name, double lat, double lon){
    
    LNode newNode = new LNode(name,lat,lon);
    if (head == null) {
      
        head = newNode;               //if the list is empty then the newNode will be placed at the head because
                                      //there is nothing to compare it to
      
        return 0;
    }
    
    if (head.longitude>=newNode.longitude){
      
      newNode.next = head;                 //if the head is larger in longitude than the newNode then the newNode will
      head=newNode;                       //be the new head and the head value will be the second element in the list
      return 0;
    }         
    else {
       LNode cNode = head;
        int counter = 1;
    
        while (cNode.next != null) {
                                                      //otherwise go through the list until there is a node that has a larger
                                                       //longitutude and then place the newNode before it
            if(cNode.next.longitude >= newNode.longitude){
             newNode.next = cNode.next;
              
            cNode.next = newNode;         
            return counter;
            
            }
          
            counter++;
            cNode = cNode.next;
        }
       
      newNode.next = cNode.next;
              
      cNode.next = newNode;
      return counter;
      
    }
     
  }
    

  public int clearList(){
    LNode cNode = head;
    
    int counter = 0;
    if (head == null) {     //if head is null then list is empty so there is nothing to clear
        return 0;
    } 
    
    while (cNode != null) {
    LNode temp;
    temp = cNode.next;          //otherwise, the loop will traverse the list emptying every value of each node until the list ends
    cNode.name = "";
    cNode.latitude = 0;
    cNode.longitude = 0;
    cNode = temp;
      
    counter++;
    
    
    }
    
    head = null;          //to completely clear the list finally the head is set to null to signify an empty list
    
    return counter;  
  }

}
