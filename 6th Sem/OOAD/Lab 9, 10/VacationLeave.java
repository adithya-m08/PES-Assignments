import java.util.Date;

class VacationLeave extends LeaveRequest {
    private Date startDate;
    private Date endDate;

    public VacationLeave(String empName, Date startDate, Date endDate) {
        super(empName);
        this.startDate = startDate;
        this.endDate = endDate;
    }
    
    public void processRequest() {
        this.leaveStatus = "Approved";
        this.approvedBy = "Director";
        this.approvalDate = new Date();
        System.out.println("Vacation Leave Request Approved by " + this.approvedBy + " : " + this.empName + ", From: "
                + this.startDate + ", To: " + this.endDate);

    }

}
