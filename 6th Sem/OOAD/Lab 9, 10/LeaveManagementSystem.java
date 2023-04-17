import java.util.ArrayList;

import java.util.List;

public class LeaveManagementSystem {
    private List<LeaveRequest> leaveRequests;
    public LeaveManagementSystem() {
        leaveRequests = new ArrayList<>();
    }

    public void addLeaveRequest(LeaveRequest leaveRequest) {
        leaveRequests.add(leaveRequest);
    }
    public void processLeaveRequests() {
        for (LeaveRequest leaveRequest : leaveRequests) {
            LeaveHandler handler = getHandler(leaveRequest);
            if (handler != null) {
                handler.processRequest(leaveRequest);
                System.out.println("Leave request approved: " + leaveRequest);
            } 
            else {
                System.out.println("No handler found for leave request: " + leaveRequest);
            }
        }
    }

    private LeaveHandler getHandler(LeaveRequest leaveRequest) {
        if (leaveRequest instanceof SickLeave) {
            return new TechLead();
        } else if (leaveRequest instanceof CasualLeave) {
            return new ProjectManager();
        } else if (leaveRequest instanceof VacationLeave) {
            return new Director();
        } else {
            return null;
        }
    }
}
