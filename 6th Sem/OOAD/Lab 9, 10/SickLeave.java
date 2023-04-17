import java.util.Date;

class SickLeave extends LeaveRequest {

    public SickLeave(String empName) {
        super(empName);
    }

    public void processRequest() {
        this.leaveStatus = "Approved";
        this.approvedBy = "Tech Lead";
        this.approvalDate = new Date(System.currentTimeMillis());

        System.out.println(
                "Sick Leave Request Approved by " + this.approvedBy + " : " + this.empName + "on " + this.approvalDate);

    }

}
