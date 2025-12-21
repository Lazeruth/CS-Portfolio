package services;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

class TaskTest {

    @Test
    void testTaskClass() {
        Task task = new Task("12345", "Task Name", "Task Description");
        assertEquals("12345", task.getTaskId());
        assertEquals("Task Name", task.getName());
        assertEquals("Task Description", task.getDescription());
    }

    @Test
    void testTaskClassInvalidName() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Task("12345", "Name that is definitely way too long for the limit", "Description");
        });
    }
}