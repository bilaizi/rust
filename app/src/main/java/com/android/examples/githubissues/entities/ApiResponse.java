package com.android.examples.githubissues.entities;

import java.util.List;
// We will use ApiResponse to communicate data from Repository to ViewModel and ultimately to Activity.
// So if we get any error while fetching data from the remote api,
// we will set Error in the ApiResponse, else we will set the list of Issue objects into it.
public class ApiResponse {
    private List<Issue> issues;
    private Throwable error;

    public ApiResponse(List<Issue> issues) {
        this.issues = issues;
        this.error = null;
    }

    public ApiResponse(Throwable error) {
        this.error = error;
        this.issues = null;
    }

    public List<Issue> getIssues() {
        return issues;
    }

    public Throwable getError() {
        return error;
    }
}