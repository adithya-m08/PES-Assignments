import java.util.Date;

class CasualLeave extends LeaveRequest {

    
    private String reason;
    public CasualLeave(String empName, String reason) {
        super(empName);
        this.reason = reason;
    }

    
    public void processRequest() {
        this.leaveStatus = "Approved";
        this.approvedBy = "Project Manager";
        this.approvalDate = new Date(System.currentTimeMillis());
        System.out.println("Casual Leave Request Approved by " + this.approvedBy + " : " + this.empName + ", Reason: "
                + this.reason + " on " + this.approvalDate);
    }
}
