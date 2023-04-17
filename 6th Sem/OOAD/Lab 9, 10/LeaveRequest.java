import java.util.Date;

abstract class LeaveRequest {

    protected String empName;
    protected String leaveStatus;
    protected String approvedBy;
    protected Date requestDate;
    protected Date approvalDate;

    public LeaveRequest(String empName) {
        this.empName = empName;
        this.leaveStatus = "New";
        this.requestDate = new Date();

    }

    public String getEmpName() {
        return empName;
    }

    public String getLeaveStatus() {
        return leaveStatus;
    }

    public String getApprovedBy() {
        return approvedBy;
    }

    public Date getRequestDate() {
        return requestDate;
    }

    public Date getApprovalDate() {
        return approvalDate;
    }

    public void setLeaveStatus(String leaveStatus) {
        this.leaveStatus = leaveStatus;
    }

    public void setApprovedBy(String approvedBy) {
        this.approvedBy = approvedBy;
    }

    public void setApprovalDate(Date approvalDate) {
        this.approvalDate = approvalDate;
    }

    public abstract void processRequest();

}
