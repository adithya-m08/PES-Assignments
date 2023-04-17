class TechLead extends LeaveHandler {
    
    public void processRequest(LeaveRequest leave) {
        if (leave instanceof SickLeave) {
            leave.processRequest();
        } else if (nextHandler != null) {
            nextHandler.processRequest(leave);
        }
    }
}
