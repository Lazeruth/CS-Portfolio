package services;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class TaskServiceTest {
    TaskService service;

    @BeforeEach
    void setUp() {
        service = new TaskService();
    }

    @Test
    void testAddTask() {
        Task task = new Task("1", "Name", "Desc");
        service.addTask(task);
        assertEquals(1, service.getTaskList().size());
    }

    @Test
    void testUpdateTask() {
        Task task = new Task("1", "Name", "Desc");
        service.addTask(task);
        service.updateTask("1", "New Name", "New Desc");
        assertEquals("New Name", service.getTaskList().get(0).getName());
    }
}