package services;

import java.util.ArrayList;
import java.util.List;

public class TaskService {
    private List<Task> tasks = new ArrayList<>();

    public void addTask(Task newTask) {
        for (Task t : tasks) {
            if (t.getTaskId().equals(newTask.getTaskId())) {
                throw new IllegalArgumentException("Task ID already exists");
            }
        }
        tasks.add(newTask);
    }

    public void deleteTask(String taskId) {
        tasks.removeIf(t -> t.getTaskId().equals(taskId));
    }

    public void updateTask(String taskId, String newName, String newDescription) {
        for (Task t : tasks) {
            if (t.getTaskId().equals(taskId)) {
                if (newName != null) t.setName(newName);
                if (newDescription != null) t.setDescription(newDescription);
                return;
            }
        }
        throw new IllegalArgumentException("Task ID not found");
    }
    
    public List<Task> getTaskList() { return tasks; }
}