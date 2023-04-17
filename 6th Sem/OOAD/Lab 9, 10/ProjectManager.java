class ProjectManager extends LeaveHandler {

    public void processRequest(LeaveRequest leave) {
        if (leave instanceof CasualLeave) {
            leave.processRequest();

        } else if (nextHandler != null) {
            nextHandler.processRequest(leave);
        }
    }
}
