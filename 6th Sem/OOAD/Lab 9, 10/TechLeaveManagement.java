import java.util.Date;
import java.util.Scanner;

public class TechLeaveManagement {
    public static void main(String[] args) {
        LeaveHandler techLead = new TechLead();
        LeaveHandler projectManager = new ProjectManager();
        LeaveHandler director = new Director();

        techLead.setNextHandler(projectManager);
        projectManager.setNextHandler(director);

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the name of the Employee: ");
        String ename = sc.next();

        System.out.println("Enter 1 for Sick Leave: ");
        System.out.println("Enter 2 for Casual Leave: ");
        System.out.println("Enter 3 for Vacation Leave: ");
        int leave = sc.nextInt();

        switch (leave) {
            case 1:
                System.out.println("Processing Sick Leave Request for " + ename);
                LeaveRequest sickLeave = new SickLeave(ename);
                techLead.processRequest(sickLeave);
                break;
            case 2:
                System.out.println("Enter the reason for leave: ");
                String r = sc.next();
                System.out.println("Processing Casual Leave Request for " + ename);
                LeaveRequest casualLeave = new CasualLeave(ename, r);
                techLead.processRequest(casualLeave);
                break;
            case 3:
                System.out.println("Enter the number of days: ");
                int nod = sc.nextInt();
                long nod1 = nod * 86400000;
                System.out.println("Processing Vacation Leave Request for " + ename);
                LeaveRequest vacationLeave = new VacationLeave(ename, new Date(),
                        new Date(System.currentTimeMillis() + nod1));
                techLead.processRequest(vacationLeave);
                break;
            default:
                System.out.println("Invalid Choice");
        }
        sc.close();
    }
}
