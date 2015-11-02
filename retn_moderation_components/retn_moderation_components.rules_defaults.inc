<?php
/**
 * @file
 * retn_moderation_components.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function retn_moderation_components_default_rules_configuration() {
  $items = array();
  $items['rules_approve_content'] = entity_import('rules_config', '{ "rules_approve_content" : {
      "LABEL" : "Approve Content",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "content_moderation" : { "label" : "Content Moderation", "type" : "node" },
        "moderation_value" : { "label" : "Moderation Value", "type" : "text", "parameter" : false }
      },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "content-moderation" ],
            "type" : { "value" : {
                "air_request" : "air_request",
                "event_coverage_request" : "event_coverage_request",
                "cm_project" : "cm_project",
                "cm_show" : "cm_show"
              }
            }
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "content-moderation:field-moderation-content" ],
            "value" : "2"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "moderation_value" ]
    }
  }');
  $items['rules_needs_review'] = entity_import('rules_config', '{ "rules_needs_review" : {
      "LABEL" : "Needs Review",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "content_moderation" : { "label" : "Content Moderation", "type" : "node" },
        "moderation_value" : { "label" : "Moderation Value", "type" : "text", "parameter" : false }
      },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "content-moderation" ],
            "type" : { "value" : {
                "air_request" : "air_request",
                "event_coverage_request" : "event_coverage_request",
                "cm_project" : "cm_project",
                "cm_show" : "cm_show"
              }
            }
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "content-moderation:field-moderation-content" ],
            "value" : "1"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "moderation_value" ]
    }
  }');
  $items['rules_producer_moderation_approved'] = entity_import('rules_config', '{ "rules_producer_moderation_approved" : {
      "LABEL" : "Producer Moderation Approved",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "19" : "19" } }
          }
        },
        { "NOT user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "4" : "4", "14" : "14", "16" : "16", "15" : "15", "11" : "11" } },
            "operation" : "OR"
          }
        },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cm_project" : "cm_project", "cm_show" : "cm_show" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-moderation-content" ], "value" : "2" } },
        { "node_publish" : { "node" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_reject_content'] = entity_import('rules_config', '{ "rules_reject_content" : {
      "LABEL" : "Decline Content",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "content_moderation" : { "label" : "Content Moderation", "type" : "node" },
        "moderation_value" : { "label" : "Moderation Value", "type" : "text", "parameter" : false }
      },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "content-moderation" ],
            "type" : { "value" : {
                "air_request" : "air_request",
                "event_coverage_request" : "event_coverage_request",
                "cm_project" : "cm_project",
                "cm_show" : "cm_show"
              }
            }
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "content-moderation:field-moderation-content" ],
            "value" : "3"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "moderation_value" ]
    }
  }');
  return $items;
}
