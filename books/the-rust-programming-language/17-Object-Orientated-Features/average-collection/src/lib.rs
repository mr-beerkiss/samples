pub struct AveragedCollection {
    list: Vec<i32>,
    average: f64,
}

impl AveragedCollection {
    pub fn add(&mut self, value: i32) {
        self.list.push(value);
        self.update_average();
    }

    pub fn remove(&mut self) -> Option<i32> {
        let result = self.list.pop();
        match result {
            Some(value) => {
                self.update_average();
                Some(value)
            },
            None => None,
        }
    }

    pub fn average(&self) -> f64 {
        self.average
    }

    fn update_average(&mut self) {
        let total: i32 = self.list.iter().sum();
        self.average = total as f64 / self.list.len() as f64;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_updates_average_when_adding() {
        let mut avg_col = AveragedCollection { 
            list: vec![1, 2],
            average: 0 as f64,
        };
        
        avg_col.add(3);

        assert_eq!(avg_col.average(), 2 as f64);
    }

    #[test]
    fn it_updates_the_average_when_removing() {
        let mut avg_col = AveragedCollection { 
            list: vec![1, 2, 3],
            average: 0 as f64,
        };

        avg_col.remove();

        assert_eq!(avg_col.average(), 1.5);
    }

    #[test]
    fn remove_returns_the_last_item_on_the_list() {
        let mut avg_col = AveragedCollection { 
            list: vec![1, 2, 3],
            average: 0 as f64,
        };

        let popped_val = avg_col.remove().unwrap();

        assert_eq!(popped_val, 3);
    }
}
