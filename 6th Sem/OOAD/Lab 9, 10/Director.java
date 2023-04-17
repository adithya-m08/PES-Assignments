class Director extends LeaveHandler {

    public void processRequest(LeaveRequest leave) {
        if (leave instanceof VacationLeave) {
            leave.processRequest();
        } else if (nextHandler != null) {
            nextHandler.processRequest(leave);
        }
    }
}
